include constant, vector3, ray, scene, intersection
import random

const
    depthLimit = 5 # 反射する回数

proc radiance* (ray: Ray, depth: int): Vector3 =
    if depth == depthLimit: # 反射深度
        return vector3()
    var intersection = near_intersection(ray)
    if intersection == nil: # 衝突しない場合は暗い
        # return vector3()
        return vector3(1,1,1)

    # if intersection.emission != vector3(): # 光源との衝突
    #     return intersection.emission
    
    result = vector3() # radianceの初期化
    
    # DIFFUSE(完全拡散面)
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
    
    # コサイン項を使った重点的サンプリング
    let
        phi = 2 * kPI * rand(1.0) # 半球の360度回転方向
        theta = arccos(rand(1.0)) # 仰角
    var new_ray = ray(intersection.position, normalize(u * cos(phi) * cos(theta) + v * sin(phi) * cos(theta)  + w * sin(theta)))
    result = result + radiance(new_ray, depth + 1) # incoming_radiance
    result = mult(intersection.color, result)
