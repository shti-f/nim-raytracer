import math, random

# Vector3の定義
type Vector3 = array[0..2, float]

proc vinit(): Vector3 =
    [0.0, 0.0, 0.0]

proc vinit(a: float, b: float, c: float): Vector3 =
    [a, b, c]

proc `$` (a: Vector3): string =
    "[" & $a[0] & ", " & $a[1] & ", " & $a[2] & "]"

proc `+`(left: Vector3, right: Vector3): Vector3 =
    [left[0] + right[0], left[1] + right[1], left[2] + right[2]]

proc `-`(left: Vector3, right: Vector3): Vector3 =
    [left[0] - right[0], left[1] - right[1], left[2] - right[2]]

proc `*`(left: float, right: Vector3): Vector3 =
    [left * right[0], left * right[1], left * right[2]]

proc `*`(left: Vector3, right: float): Vector3 =
    [left[0] * right, left[1] * right, left[2] * right]

proc dot(left: Vector3, right: Vector3): float =
    left[0] * right[0] + left[1] * right[1] + left[2] * right[2]

proc cross(left: Vector3, right: Vector3): Vector3 =
    [left[1] * right[2] - right[2] * left[1], left[2] * right[0] - right[0] * left[2], left[0] * right[1] - right[1] * left[0]]

proc mult(left: Vector3, right: Vector3): Vector3 = #色の計算に使うらしい
    [left[0] * right[0], left[1] * right[1], left[2] * right[2]]

proc norm(this: Vector3): float =
    this.dot(this).sqrt

proc normalize(this: Vector3): Vector3 =
     this * (1 / this.norm)

# Rayの定義
type Ray = ref object of RootObj
    o: Vector3
    d: Vector3

proc rinit(o: Vector3, d: Vector3): Ray =
    Ray(o: o, d: d)

# Reflectionの列挙
type Reflection = enum
    DIFF, SPEC, REFR

# Sphereの定義
type Sphere = ref object of RootObj
    rad: float
    pos: Vector3
    emi: Vector3
    col: Vector3
    refl: Reflection

proc sinit(rad: float, pos: Vector3, emi: Vector3, col: Vector3, refl: Reflection): Sphere =
    Sphere(rad: rad, pos: pos, emi: emi, col: col, refl: refl)

proc intersect(this: Sphere, r: Ray): float =
    var op: Vector3 = this.pos - r.o
    var
        t: float
        eps: float = 1.0e-4
        b = op.dot(r.d)
        det = b * b - op.norm + this.rad * this.rad
    if det < 0:
        return 0
    else:
        det = det.sqrt
    if b - det > eps :
        return b - det
    else:
        if b + det > eps :
            return b + det
        else:
            return 0

# Sphereの配置
var spheres: seq[Sphere] = @[
    sinit(1.0e5, vinit(1e5+1, 40.8, 81.6), vinit(), vinit(0.75, 0.25, 0.25), DIFF), # Left
    sinit(1.0e5, vinit(-1e5+99, 40.8, 81.6), vinit(), vinit(0.25, 0.25, 0.75), DIFF), # Rght
    sinit(1.0e5, vinit(50, 40.8, 1e5), vinit(), vinit(0.75, 0.75, 0.75), DIFF), # Back
    sinit(1.0e5, vinit(50, 40.8, -1e5+170), vinit(), vinit(), DIFF), # Frnt
    sinit(1.0e5, vinit(50, -1e5+81.6, 81.6), vinit(), vinit(0.75, 0.75, 0.75), DIFF), # Botm
    sinit(1.0e5, vinit(50, -1e5-81.6, 81.6), vinit(), vinit(0.75, 0.25, 0.25), DIFF), # Top
    sinit(16.5, vinit(27,16.5,47), vinit(), vinit(1,1,1)*0.999, SPEC), # Mirr 
    sinit(16.5, vinit(73,16.5,78), vinit(), vinit(1,1,1)*0.999, REFR), # Glas 
    sinit(600, vinit(50,681.6-0.27,81.6), vinit(12,12,12), vinit(), DIFF) # Lite 
]

# inline関数の定義？
proc clamp(x: float) :float {.inline.} =
    if x < 0:
        return 0
    else:
        if x > 1:
            return 1
        else:
            return x

proc toInt(x: float): int {.inline.}=
    cast[int](pow(clamp(x), 1/2.2) * 255 + 0.5)

proc intersect(r: Ray, t: float, id: int): bool {.inline.} = #TODO tの意味は？
    var
        n: float = sizeof(spheres) / sizeof(Sphere)
        d : float
        inf = 1e20
        t = inf
        id = id
    for i in countdown(cast[int](n), 0):
        var d = spheres[i].intersect(r)
        if d != 0 and d < t:
            t=d
            id=i

# Radianceの定義
proc radiance(r: Ray, depth: int, Xi: pointer): Vector3 =
    var
        t: float
        id = 0
    if not intersect(r, t, id):
        return vinit()
    var
        depth: int = depth
        obj: Sphere = spheres[id] # the hit object 
        x: Vector3 = r.o + r.d * t
        n: Vector3 = (x - obj.pos).normalize
        f: Vector3 = obj.col
        nl: Vector3
    if n.dot(r.d) < 0:
        nl = n
    else:
        nl = n * -1
    var p: float # max refl
    if f[0] > f[1] and f[0] > f[2]:
        p = f[0]
    else:
        if f[1] > f[2]:
            p = f[1]
        else:
            p = f[2]
    depth += 1
    if depth > 5: # R.R.
        if random(1) * Xi < p:
            f = f * (1 / p)
        else:
            return obj.emi
    if obj.refl == DIFF: # Ideal DIFFUSE reflection
        var 
            r1: float = 2 * PI * erand48(Xi)
            r2: float = erand48(Xi)
            r2s: float = sqrt(r2)
            w: Vector3 = nl
            u: Vector3
        if abs(w[0]) > 0.1:
            u = vinit(0.0, 1.0, 0.0).cross(w).normalize
        else:
            u = vinit(1.0, 0.0, 0.0).cross(w).normalize
        var
            v: Vector3 = w.cross(u)
            d: Vector3 = (u*cos(r1)*r2s + v*sin(r1)*r2s + w*sqrt(1-r2)).normalize()
        return obj.emi + f.mult(radiance(rinit(x,d),depth,Xi)); 
    elif obj.refl == SPEC: # Ideal SPECULAR reflection 
        return obj.emi + f.mult(radiance(rinit(x, r.d - n * 2 * n.dot(r.d)), depth, Xi))
    var
        reflRay: Ray = rinit(x, r.d-n*2*n.dot(r.d)) # Ideal dielectric REFRACTION 
        into: bool = n.dot(nl) > 0 # Ray from outside going in? 
        nc: float = 1
        nt:float = 1.5
        nnt: float
    if into:
        nnt = nc/nt
    else:
        nnt = nt/nc
    var
        ddn: float = r.d.dot(nl)
        cos2t: float = 1 - nnt * nnt * (1 - ddn * ddn)
    if cos2t < 0: # Total internal reflection 
        return obj.emi + f.mult(radiance(reflRay, depth, Xi))
    var tdir: Vector3 = (r.d*nnt - n*((if into:1 else: -1)*(ddn*nnt+sqrt(cos2t)))).norm()
    var
        a: float = nt - nc
        b: float = nt + nc
        R0: float = a * a / (b * b)
        c: float = 1 - (if into: -ddn else: tdir.dot(n))
        Re: float = R0 + (1 - R0) * c * c * c * c * c
        Tr: float = 1 - Re
        P: float = 0.25 + 0.5 * Re
        RP: float = Re / P
        TP: float = Tr / (1 - P) 
    return obj.emi + f.mult(
        if depth > 2:
            if erand48(Xi) < P: # Russian roulette 
                radiance(reflRay,depth,Xi)*RP
            else:
                radiance(rinit(x,tdir),depth,Xi)*TP
        else: 
            radiance(reflRay,depth,Xi)*Re+radiance(rinit(x,tdir),depth,Xi)*Tr)

# メイン
const
    width = 1024
    height = 768
    samps = 1


type intArray = array[0..2, int]
var img : array[0..width, array[0..height, intArray]]

for i in 0..high(img):
    for j in 0..high(img[i]):
        img[i][j] = [i * 10, j * 10, (i + j) * 10]

block:
  var f : File = open("img.ppm" ,FileMode.fmWrite)
  defer :
    close(f)
    echo "closed"
  f.writeLine "P3"
  f.writeLine "# The P3 means colors are in ASCII, then " & $width & " columns and " & $height & " rows, then 255 for max color, then RGB triplets"
  f.writeLine $width & " " & $height
  f.writeLine "255"
  for i in 0..high(img):
    for j in 0..high(img[i]):
        f.writeLine $img[i][j][0] & " " & $img[i][j][1] & " " & $img[i][j][2]
