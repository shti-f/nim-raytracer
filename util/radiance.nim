include vector3, ray, objects, constant, intersection, scene
import random

const
    depthLimit = 5 # 反射する回数

proc radiance* (ray: Ray, depth: int): Vector3 =
    var intersection = near_intersection(ray)
    if intersection == nil: return vector3(1,1,1)
    if depth == depthLimit: return vector3()
    result = vector3()
    # DIFFUSE
    # orienting_normalの方向を基準とした正規直交基底(w, u, v)を作る。この基底に対する半球内で次のレイを飛ばす。
    var orienting_normal =
        if dot(intersection.normal , ray.direction) < 0.0: intersection.normal
        else: -1 * intersection.normal
    var u, v, w: Vector3
    w = orienting_normal
    if abs(w[0]) > kEPS: # ベクトルwと直交するベクトルを作る。w.xが0に近い場合とそうでない場合とで使うベクトルを変える。
        u = normalize(cross(vector3(0.0, 1.0, 0.0), w))
    else:
        u = normalize(cross(vector3(1.0, 0.0, 0.0), w))
    v = cross(w, u)
    # return v / 2 + vector3(0.5, 0.5, 0.5) # s
    # return u / 2 + vector3(0.5, 0.5, 0.5) # tan
    
    # コサイン項を使った重点的サンプリング
    let
        phi = 2 * kPI * rand(1.0) # 半球のxy方向の回転
        theta = arccos(rand(1.0)) # z方向の角度
    var new_ray = Ray(origin: intersection.position, direction: normalize(u * sin(phi) * cos(theta) + v * sin(phi) * sin(theta)  + w * cos(theta)))
    result = result + radiance(new_ray, depth + 1) # incoming_radiance
    result = mult(intersection.color, result)
