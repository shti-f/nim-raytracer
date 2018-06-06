import times
import util/intersection, util/fileWrite

const
    width = 512
    height = 512

# cameraの配置
type Camera = ref object of RootObj
    position: Vector3
    pinhole: Vector3

let camera = Camera(position: vinit(0, 0, 5), pinhole: vinit(0, 0, 4))

type Radience = ref object of RootObj
    value: float

proc radience (intersection: Intersection): Radience =
    echo ""

# sphereの配置
let spheres = [
    Sphere(radius: 1, position: vinit(0, 0, 0), emission: vinit(), color: vinit(1, 0, 0)),
    # sinit(1e5, vinit(0, 0, 1e5+2), vinit(), vinit(0,1,0)),
]

# imgに格納
var img: array[width, array[height, Vector3]]
for x in 0..<width: # 右にx、下にy、奥にz
    for y in 0..<height:
        # z軸負方向にあるスクリーンから原点に向けてrayを飛ばす
        var o = camera.position - vinit((width - 2 * x) / width, (height - 2 * y) / height, 0)
        var ray = rinit(camera.pinhole, (camera.pinhole - o).normalize)
        # sphereとの衝突判定
        var near = Intersection(distance: 1e15) # 一番近いsphereを格納する
        for i in 0..<spheres.len:
            var intersection = intersect(ray, spheres[i])
            if intersection != nil and intersection.distance < near.distance:
                near = intersection
        img[x][y] = near.normal / 2 + vinit(0.5, 0.5, 0.5)

# 出力
ppmFileWrite("img" & getTime().local.format("yyyyMMdd-HHmmss") & ".ppm", img)
