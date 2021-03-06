import math, times

import ../edupt, vector3
type Img* = array[width, array[height, Vector3]]

# clampとtoInt
proc clamp(x: float): float =
    if x < 0:
        0.0
    elif x > 1:
        1.0
    else:
        x

proc to255(x: float): int =
    int(pow(clamp(x), 1 / 2.2) * 255)

# ppmの出力
proc ppmFileWrite*(img: auto) =
    var
        fileName = "img" & getTime().local.format("yyyyMMdd-HHmmss") & ".ppm"
        f : File = open("img/" & fileName ,FileMode.fmWrite)
        width = img.len
        height = img[0].len
    defer :
        close(f)
        echo "export: " & fileName
        echo "done"
    f.writeLine "P3"
    f.writeLine "# The P3 means colors are in ASCII, then " & $width & " columns and " & $height & " rows, then 255 for max color, then RGB triplets"
    f.writeLine $width & " " & $height
    f.writeLine "255"
    for y in countdown(high(img[0]),low(img[0])):
        for x in low(img)..high(img):
            f.writeLine $to255(img[x][y][0]) & " " & $to255(img[x][y][1]) & " " & $to255(img[x][y][2])
