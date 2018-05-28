# Sphereの定義
type Sphere = ref object of RootObj
    radius: float
    position: Vector3

proc sinit(radius: float, position: Vector3): Sphere =
    Sphere(radius: radius, position: position)

type Intersection = ref object of RootObj
    isIntersect: bool
    distance: float
    position: Vector3
    normal: Vector3 # 法線ベクトル

# 衝突判定
proc intersect(r: Ray, sphere: Sphere): Intersection =
    var
        po = r.origin - sphere.position
        det = pow(r.direction.dot(po), 2) - po.dot(po) + pow(sphere.radius, 2) # rayとsphereの判別式
        EPS = 1e-10
    if det < 0: # 判別式負、当たらない
        return Intersection(isIntersect: false)
    var
        tminus = - r.direction.dot(po) - det.sqrt
        tplus = - r.direction.dot(po) + det.sqrt
    if tminus < EPS and tplus < EPS:
        return Intersection(isIntersect: false)
    var distance = if tminus < 0: tplus
        else: tminus
    var
        position = r.origin + distance * r.direction
        normal = (position - sphere.position).normalize
    return Intersection(isIntersect: true, distance: distance, position: position, normal: normal)