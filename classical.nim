import times
import util/intersection, util/fileWrite

const
    width = 512
    height = 512

# sphereの配置
let spheres = [
    sinit(0.3, vector3(0, 0, 1), vector3(), vector3(0.99, 0.99, 0.99)),
    # sinit(0.5, vector3(0, 0, 3)),
    # sinit(1e5, vector3(1e5+1000, 0, 1)), # Left
    # sinit(1e5, vector3(-1e5+99, 40.8, 81.6)), # Rght
    sinit(1e5, vector3(0, 0, 1e5+2), vector3(), vector3(0.25, 0.25, 0.75)), # Back
    # sinit(1e5, vector3(50, 40.8, -1e5+170)), # Frnt
    # sinit(1e5, vector3(50, -1e5+81.6, 81.6)), # Botm
    # sinit(1e5, vector3(50, -1e5-81.6, 81.6)), # Top
]

# imgに格納
var img: array[width, array[height, Vector3]]
for x in 0..<width: # 右にx、下にy、奥にz
    for y in 0..<height:
        # z軸負方向にあるスクリーンから原点に向けてrayを飛ばす
        var o = vector3((2 * x - width) / width, (2 * y - height) / height, -1.0)
        var ray = rinit(o, (vector3() - o).normalize)
        # sphereとの衝突判定
        var near = Intersection(distance: 1e15) # 一番近いsphereを格納する
        for i in 0..<spheres.len:
            var intersection = intersect(ray, spheres[i])
            if intersection != nil and intersection.distance < near.distance:
                near = intersection
        img[x][y] = near.normal

# 出力
ppmFileWrite("img" & getTime().local.format("yyyyMMdd-HHmmss") & ".ppm", img)
