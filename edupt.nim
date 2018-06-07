import util/radiance, util/fileWrite

const
    width = 512
    height = 512

# cameraの配置
type Camera = ref object of RootObj
    position: Vector3
    pinhole: Vector3

let camera = Camera(position: vector3(0, 0, 5), pinhole: vector3(0, 0, 4))

const
    depth = 5 # 反射する回数
    samples = 10 # １つのピクセルからrayを飛ばす回数

type Radiance = ref object of RootObj
    value: float
    color: Vector3

proc radiance (intersection: Intersection, ray: Ray): Radiance =
    if intersection == nil: return Radiance(value: 0, color: vector3()) #TODO
    # DIFFUSE
    # orienting_normalの方向を基準とした正規直交基底(w, u, v)を作る。この基底に対する半球内で次のレイを飛ばす。
    var orienting_normal =
        if dot(intersection.normal , ray.direction) < 0.0: intersection.normal
        else: -1 * intersection.normal
    var w, u, v: Vector3
    w = orienting_normal
    if abs(w[0]) > kEPS: # ベクトルwと直交するベクトルを作る。w.xが0に近い場合とそうでない場合とで使うベクトルを変える。
        u = normalize(cross(vector3(0.0, 1.0, 0.0), w))
    else:
        u = normalize(cross(vector3(1.0, 0.0, 0.0), w))
    v = cross(w, u)
    # // コサイン項を使った重点的サンプリング
    const
        r1 = 2 * kPI * rand(1.0)
        r2 = arccos(rand(1.0))
    var dir = normalize((
        u * cos(r1) * r2 +
        v * sin(r1) * r2 +
        w * sqrt(1.0 - r2)))

    incoming_radiance = radiance(Ray(intersection.position, dir), rnd, depth+1)
    # // レンダリング方程式に対するモンテカルロ積分を考えると、outgoing_radiance = weight * incoming_radiance。
    # // ここで、weight = (ρ/π) * cosθ / pdf(ω) / R になる。
    # // ρ/πは完全拡散面のBRDFでρは反射率、cosθはレンダリング方程式におけるコサイン項、pdf(ω)はサンプリング方向についての確率密度関数。
    # // Rはロシアンルーレットの確率。
    # // 今、コサイン項に比例した確率密度関数によるサンプリングを行っているため、pdf(ω) = cosθ/π
    # // よって、weight = ρ/ R。
    weight = now_object.color #/ russian_roulette_probability
    echo ""

# sphereの配置
let spheres = [
    Sphere(radius: 1, position: vector3(0, 0, 0), emission: vector3(), color: vector3(1, 0, 0)),
    # sinit(1e5, vector3(0, 0, 1e5+2), vector3(), vector3(0,1,0)),
]

# imgに格納
var img: array[width, array[height, Vector3]]
for x in 0..<width: # 右にx、下にy、奥にz
    for y in 0..<height:
        # z軸負方向にあるスクリーンから原点に向けてrayを飛ばす
        var o = camera.position - vector3((width - 2 * x) / width, (height - 2 * y) / height, 0)
        var ray = rinit(camera.pinhole, (camera.pinhole - o).normalize)
        # sphereとの衝突判定
        var near = Intersection(distance: 1e15) # 一番近いsphereを格納する
        for i in 0..<spheres.len:
            var intersection = intersect(ray, spheres[i])
            if intersection != nil and intersection.distance < near.distance:
                near = intersection
        img[x][y] = near.normal / 2 + vector3(0.5, 0.5, 0.5)

# 出力
ppmFileWrite(img)
