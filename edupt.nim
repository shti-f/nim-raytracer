import times
import util/intersection, util/fileWrite

const
    width = 512
    height = 512

# cameraの配置
type Camera = ref object of RootObj
    position: Vector3
    direction: Vector3

let camera = Camera(position: vinit(50, 50, -220), direction: vinit(0, -0.04, 1).normalize)



# sphereの配置
let spheres = [
    sinit(0.3, vinit(0, 0, 1), vinit(), vinit(0.99, 0.99, 0.99)),
    # sinit(0.5, vinit(0, 0, 3)),
    # sinit(1e5, vinit(1e5+1000, 0, 1)), # Left
    # sinit(1e5, vinit(-1e5+99, 40.8, 81.6)), # Rght
    sinit(1e5, vinit(0, 0, 1e5+2), vinit(), vinit(0.25, 0.25, 0.75)), # Back
    # sinit(1e5, vinit(50, 40.8, -1e5+170)), # Frnt
    # sinit(1e5, vinit(50, -1e5+81.6, 81.6)), # Botm
    # sinit(1e5, vinit(50, -1e5-81.6, 81.6)), # Top
]

# imgに格納
var img: array[width, array[height, Vector3]]
for x in 0..<width: # 右にx、下にy、奥にz
    for y in 0..<height:
        # z軸負方向にあるスクリーンから原点に向けてrayを飛ばす
        var o = vinit((2 * x - width) / width, (2 * y - height) / height, -1.0)
        var ray = rinit(o, (vinit() - o).normalize)
        # sphereとの衝突判定
        var near = Intersection(distance: 1e15) # 一番近いsphereを格納する
        for i in 0..<spheres.len:
            var intersection = intersect(ray, spheres[i])
            if intersection != nil and intersection.distance < near.distance:
                near = intersection
        img[x][y] = near.color

# 出力
ppmFileWrite("img" & getTime().local.format("yyyyMMdd-HHmmss") & ".ppm", img)
