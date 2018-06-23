import algorithm
import vector3

type SurfaceType* = enum
    DIFFUSE,
    MIRROR,
    FRESNEL

# Sphereの定義
type Sphere* = ref object of RootObj
    radius*: float
    position*: Vector3
    emission*: Vector3
    color*: Vector3
    surface*: SurfaceType

proc sphere*(radius: float, position: Vector3, emission: Vector3): Sphere = # 光源
    Sphere(radius: radius, position: position, emission: emission)

proc sphere*(radius: float, position: Vector3, color: Vector3, surface: SurfaceType): Sphere =
    Sphere(radius: radius, position: position, color: color, surface: surface)

# sceneの配置
let spheres* = [
    # sphere(8  , vector3(40, 40.8, 40.8)    , vector3(0.75)          , DIFFUSE),
    # sphere(600 , vector3(50, 40.8, 40.8)    ,vector3(0.75,0.25,0.25) , DIFFUSE),
    sphere(1e5 , vector3(0, -1e5-2, 0)      , vector3()              , DIFFUSE), 
    sphere(1e5 , vector3(1e5+1,40.8,81.6)   , vector3(0.75,0.25,0.25),  DIFFUSE), #右
    sphere(1e5 , vector3(-1e5+99,40.8,81.6) , vector3(0.25,0.25,0.75),  DIFFUSE), #左
    sphere(1e5 , vector3(50,40.8,1e5)       , vector3(0.75)          ,  DIFFUSE), #奥
    sphere(1e5 , vector3(50,1e5,81.6)       , vector3(0.75)          ,  DIFFUSE), #床
    sphere(1e5 , vector3(50,-1e5+81.6,81.6) , vector3(0.75)          ,  DIFFUSE), #天井
    sphere(16.5, vector3(27,16.5,47)        , vector3(0.999)         ,  DIFFUSE), #sphere2
    sphere(16.5, vector3(73,16.5,78)        , vector3(0.999)         ,  DIFFUSE), #sphere1
    # sphere(600 , vector3(50,681.6-0.27,81.6), vector3(12)), # 光源
    sphere(10   , vector3(50,40,81.6), vector3(12)), # 光源
]

