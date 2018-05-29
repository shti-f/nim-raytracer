# Rayの定義
type Ray* = ref object of RootObj
    origin*: Vector3
    direction*: Vector3

proc rinit*(o: Vector3, d: Vector3): Ray =
    Ray(origin: o, direction: d)

