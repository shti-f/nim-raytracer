include vector3, ray, objects, constant, intersection, scene
import random

const
    depthLimit = 5 # 反射する回数

proc radiance* (ray: Ray, depth: int, intersection: Intersection): Vector3 =
    if depth == depthLimit: return vector3()
    result = vector3()
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
    let
        r1 = 2 * kPI * rand(1.0)
        r2 = arccos(rand(1.0))
    var dir = normalize(u * cos(r1) * r2 + v * sin(r1) * r2 + w * sqrt(1.0 - r2))
    # // レンダリング方程式に対するモンテカルロ積分を考えると、outgoing_radiance = weight * incoming_radiance。
    # // ここで、weight = (ρ/π) * cosθ / pdf(ω) / R になる。
    # // ρ/πは完全拡散面のBRDFでρは反射率、cosθはレンダリング方程式におけるコサイン項、pdf(ω)はサンプリング方向についての確率密度関数。
    # // Rはロシアンルーレットの確率。
    # // 今、コサイン項に比例した確率密度関数によるサンプリングを行っているため、pdf(ω) = cosθ/π
    # // よって、weight = ρ/ R。
    var near = Intersection(distance: 1e6)
    for sphere in spheres:
        var new_ray = rinit(intersection.position, dir)
        var new_intersection = intersect(new_ray, sphere)
        if intersection != nil and intersection.distance < near.distance:
            near = new_intersection
    var incoming_radiance = radiance(rinit(intersection.position, dir), depth+1, near)
    result = result + incoming_radiance
    var weight = intersection.color #/ russian_roulette_probability
    return mult(weight, result)
