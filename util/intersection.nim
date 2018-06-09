type Intersection* = ref object of RootObj
    distance*: float
    position*: Vector3
    normal*: Vector3 # 法線ベクトル
    color*: Vector3

# 衝突判定
proc intersect*(r: Ray, sphere: Sphere): Intersection =
    var
        po = r.origin - sphere.position
        det = pow(r.direction.dot(po), 2) - po.dot(po) + pow(sphere.radius, 2) # rayとsphereの判別式
    if det < 0: # 判別式負、当たらない
        return nil
    var
        tminus = - r.direction.dot(po) - det.sqrt
        tplus = - r.direction.dot(po) + det.sqrt
    if tminus < kEPS and tplus < kEPS: # 近すぎるrayと両方マイナスは排除
        return nil
    var distance =
        if tminus < 0: tplus # マイナスがカメラより後ろにある場合
        else:          tminus # sphereに2回当たる手前
    var
        position = r.origin + distance * r.direction
        normal = (position - sphere.position).normalize
    return Intersection(distance: distance, position: position, normal: normal, color: sphere.color)