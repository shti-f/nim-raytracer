import util/radiance, util/fileWrite
import random, locks

const
    width = 512
    height = 512

# cameraの配置
type Camera = ref object of RootObj
    position: Vector3
    pinhole: Vector3

let camera = Camera(position: vector3(0, 0, 5), pinhole: vector3(0, 0, 4))

const
    samples = 10 # １つのピクセルからrayを飛ばす回数

# imgにレンダリング結果を入れていく
var img: array[width, array[height, Vector3]]
for x in 0..<width: # 右にx、下にy、奥にz
    for y in 0..<height:
        # z軸負方向にあるスクリーンからピンホールに向けてrayを飛ばす
        var pixel = camera.position - vector3((width - 2 * x) / width, (height - 2 * y) / height, 0)
        img[x][y] = vector3()
        for i in 0..<samples:
            var ssaa = vector3(rand(1.0) / width, rand(1.0) / height, 0)
            var ray = ray(camera.pinhole, (camera.pinhole - pixel - ssaa).normalize)
            img[x][y] = img[x][y] + radiance(ray, 0) / samples

# 出力
ppmFileWrite(img)
