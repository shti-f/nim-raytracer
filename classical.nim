import math, random, times
include util/vector3, util/ray, util/sphere, util/filewrite

const
    width = 512
    height = 512

# Sphereの配置
let spheres: seq[Sphere] = @[
    sinit(0.3, vinit(0, 0, 0.4)),
    # sinit(0.5, vinit(0, 0, 3)),
    # sinit(1e5, vinit(1e5+1000, 0, 1)), # Left
    # sinit(1e5, vinit(-1e5+99, 40.8, 81.6)), # Rght
    sinit(1e5, vinit(0, 0, 1e5+1)), # Back
    # sinit(1e5, vinit(50, 40.8, -1e5+170)), # Frnt
    # sinit(1e5, vinit(50, -1e5+81.6, 81.6)), # Botm
    # sinit(1e5, vinit(50, -1e5-81.6, 81.6)), # Top
]

# imgに格納
var img: array[1..width, array[1..height, Vector3]]
for x in low(img)..high(img): # 右にx、下にy、奥にz
    for y in low(img[x])..high(img[x]):
        # z軸負方向にあるスクリーンから原点に向けてrayを飛ばす
        var o = vinit((2 * x - width) / width, (2 * y - height) / height, -1.0)
        var ray = rinit(o, (vinit() - o).normalize)
        # sphereとの衝突判定
        var
            intersection: Intersection
            near = Intersection(isIntersect: false, distance: 1e15) # 一番近いsphereを格納する
        for sphere in spheres:
            intersection = intersect(ray, sphere)
            if intersection.isIntersect and intersection.distance < near.distance:
                near = intersection
        img[x][y] = near.normal

# 出力
ppmFileWrite("img" & getTime().getLocalTime.format("yyyyMMdd-HHmmss") & ".ppm", img)
