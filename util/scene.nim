import algorithm

# sphereの配置
let spheres* = [
    Sphere(radius: 1, position: vector3(0, 0, 0), emission: vector3(), color: vector3(1, 0, 0)),
    # sinit(1e5, vector3(0, 0, 1e5+2), vector3(), vector3(0,1,0)),
]

# proc intersection_scene(ray: Ray): bool =
#     for sphere in spheres:
#         if intersection(ray, sphere) is not nil:
#             return true
#     return false
