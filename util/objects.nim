# Sphereの定義
type Sphere* = ref object of RootObj
    radius*: float
    position*: Vector3
    emission*: Vector3
    color*: Vector3

proc sinit*(radius: float, position: Vector3, emission = vinit(), color: Vector3): Sphere =
    Sphere(radius: radius, position: position, emission: emission, color: color)



