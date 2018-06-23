import util/constant, util/vector3, util/ray, util/radiance
import random, locks, math

const
    width* = 512
    height* = 512

# cameraの配置
type Camera = ref object of RootObj 
    position: Vector3
    pinhole: Vector3
    up: Vector3
    fov: float # field of view (視野角)
    aspect: float
    w: Vector3
    u: Vector3
    v: Vector3

proc camera(position: Vector3, pinhole: Vector3, fov: float, up = vector3(0, 1, 0)): Camera =
    result = Camera(
        position: position,
        pinhole: pinhole,
        up: up,
        fov: fov,
        aspect: width / height
    )
    result.w = (position - pinhole).normalize
    result.u = cross(up, result.w).normalize
    result.v = cross(result.w, result.u)

var eye = vector3(50, 52, 295.6)
let cam = camera(eye, eye + vector3(0, -0.042612, -1), 30 * kPI / 180)

const
    samples = 10 # １つのピクセルからrayを飛ばす回数

# imgにレンダリング結果を入れていく

import util/fileWrite
var img : Img

for i in 0..<width * height: #左から右、を上から下に
    var
        x = i mod width # 横軸、左から右を繰り返す
        y = height - int(i / width) - 1 # 縦軸、上から順に下へ
    img[x][y] = vector3()
    for j in 0..<samples:
        var
            tf = tan(cam.fov * 0.5)
            rpx = 2 * x / width - 1
            rpy = 2 * y / height - 1
            dir = (cam.u * (cam.aspect * tf * rpx) + cam.v * (tf * rpy) + cam.w * -1).normalize #カメラ座標系からワールド座標系に変換？
        var ray = ray(cam.position, dir)
        img[x][y] = img[x][y] + radiance(ray, 0) / samples

# for x in 0..<width: # 右にx、下にy、奥にz
#     for y in 0..<height:
#         # z軸負方向にあるスクリーンからピンホールに向けてrayを飛ばす
#         var pixel = cam.position - vector3((width - 2 * x) / width, (height - 2 * y) / height, 0)
#         img[x][y] = vector3()
#         for i in 0..<samples:
#             var ssaa = vector3(rand(1.0) / width, rand(1.0) / height, 0)
#             var ray = ray(cam.pinhole, (cam.pinhole - pixel - ssaa).normalize)
#             img[x][y] = img[x][y] + radiance(ray, 0) / samples

# 出力
ppmFileWrite(img)
