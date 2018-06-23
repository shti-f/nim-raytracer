import math
import constant, vector3, ray, scene

type Intersection* = ref object of RootObj
    distance*: float
    position*: Vector3
    normal*: Vector3 # 法線ベクトル
    color*: Vector3
    emission*: Vector3
    surface*: SurfaceType

# 衝突判定
proc intersect*(ray: Ray, sphere: Sphere): Intersection =
    var
        po = ray.origin - sphere.position
        det = pow(ray.direction.dot(po), 2) - po.dot(po) + pow(sphere.radius, 2) # rayとsphereの判別式
    if det < 0: # 判別式負、当たらない
        return nil
    var
        tminus = - ray.direction.dot(po) - det.sqrt
        tplus = - ray.direction.dot(po) + det.sqrt
    if tminus < kEPS and tplus < kEPS: # 近すぎるrayと両方マイナスは排除
        return nil
    var distance =
        if tminus < 0: tplus # マイナスがカメラより後ろにある場合
        else:          tminus # sphereに2回当たる手前
    var
        position = ray.origin + distance * ray.direction
        normal = (position - sphere.position).normalize
    return Intersection(distance: distance, position: position, normal: normal, emission: sphere.emission, color: sphere.color, surface: sphere.surface)

proc near_intersection*(ray: Ray): Intersection =
    result = Intersection(distance: kINF)
    for sphere in spheres:
        var intersection = intersect(ray, sphere)
        if intersect(ray, sphere) != nil and intersection.distance < result.distance:
            result = intersection
    if result.distance == kINF:
        return nil

    