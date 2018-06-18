import algorithm

# Sphereの定義
type Sphere* = ref object of RootObj
    radius*: float
    position*: Vector3
    emission*: Vector3
    color*: Vector3

proc sphere*(radius: float, position: Vector3, emission = vector3(), color: Vector3): Sphere =
    Sphere(radius: radius, position: position, emission: emission, color: color)

# sphereの配置
let spheres* = [
    Sphere(radius: 1, position: vector3(0, 0, 0), emission: vector3(), color: vector3(1, 0, 0)),
    sphere(1e5, vector3(0, -1e5-1, 0), vector3(), vector3(0.75,0.75,0.75)), 
    # sphere(1e5, vector3(1e5, 1e5, 1e5), vector3(1e5, 1e5, 1e5), vector3())
]

