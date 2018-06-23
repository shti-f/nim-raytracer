import math

# Vector3の定義
type Vector3* = array[3, float]

proc vector3*(): Vector3 =
    [0.0, 0.0, 0.0]

proc vector3*(x: float, y: float, z: float): Vector3 =
    [x, y, z]

proc vector3*(x: float): Vector3 =
    [x, x, x]

# proc `$` (a: Vector3): string =
#     "[" & $a[0] & ", " & $a[1] & ", " & $a[2] & "]"

proc `+`*(left: Vector3, right: Vector3): Vector3 =
    [left[0] + right[0], left[1] + right[1], left[2] + right[2]]

proc `-`*(left: Vector3, right: Vector3): Vector3 =
    [left[0] - right[0], left[1] - right[1], left[2] - right[2]]

proc `*`*(left: float, right: Vector3): Vector3 =
    [left * right[0], left * right[1], left * right[2]]

proc `*`*(left: Vector3, right: float): Vector3 =
    [left[0] * right, left[1] * right, left[2] * right]

proc `/`*(left: Vector3, right: float): Vector3 =
    [left[0] / right, left[1] / right, left[2] / right]

proc dot*(left: Vector3, right: Vector3): float =
    left[0] * right[0] + left[1] * right[1] + left[2] * right[2]

proc cross*(left: Vector3, right: Vector3): Vector3 =
    [left[1] * right[2] - left[2] * right[1], left[2] * right[0] - left[0] * right[2], left[0] * right[1] - left[1] * right[0]]

proc mult*(left: Vector3, right: Vector3): Vector3 = #色の計算に使うらしい
    [left[0] * right[0], left[1] * right[1], left[2] * right[2]]

proc norm*(this: Vector3): float =
    this.dot(this).sqrt

proc normalize*(this: Vector3): Vector3 =
    this * (1 / this.norm)
