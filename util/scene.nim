import algorithm

# sphereの配置
let spheres* = [
    Sphere(radius: 1, position: vector3(0, 0, 0), emission: vector3(), color: vector3(1, 0, 0)),
    sinit(1e5, vector3(0, -1e5-1, 0), vector3(), vector3(0.75,0.75,0.75)), 
]

proc near_intersection*(ray: Ray): Intersection =
    result = Intersection(distance: kINF)
    for sphere in spheres:
        var intersection = intersect(ray, sphere)
        if intersect(ray, sphere) != nil and intersection.distance < result.distance:
            result = intersection
    if result.distance == kINF:
        return nil

