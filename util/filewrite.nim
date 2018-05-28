# clampとtoInt
proc clamp(x: float) :float =
    if x < 0:
        return 0
    else:
        if x > 1:
            return 1
        else:
            return x

proc toInt(x: float): int=
    int(clamp(x) * 255)

# ppmの出力
proc ppmFileWrite(fileName: string, img: auto) =
    var
        f : File = open("img/" & fileName ,FileMode.fmWrite)
        width = img.len
        height = img[0].len
    defer :
        close(f)
        echo "done"
    f.writeLine "P3"
    f.writeLine "# The P3 means colors are in ASCII, then " & $width & " columns and " & $height & " rows, then 255 for max color, then RGB triplets"
    f.writeLine $width & " " & $height
    f.writeLine "255"
    for y in countdown(high(img[0]),low(img[0])):
        for x in low(img)..high(img):
            f.writeLine $toInt(img[x][y][0]) & " " & $toInt(img[x][y][1]) & " " & $toInt(img[x][y][2])