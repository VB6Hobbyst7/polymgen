# Polymgen
Polymgen is a library for generating tetrahedral mesh of many polyhedrons. 
It is created with the purpose of use in solving boundary-value problems for polycrystal by the finite element method.
# Example:
```c++
// Number of cubes along the corresponding axis.
size_t nX = 3, nY = 3, nZ = 3;
psg::PolyStruct polyStruct = psg::generateCuboids(nX, nY, nZ);
pmg::PolyhedralSet polyhedr(polyStruct);

double preferredTetrahedronEdgeLength = 0.45;
polyhedr.generateMesh(preferredTetrahedronEdgeLength);
polyhedr.output(pmg::PolyhedralSet::FileType::Obj); // Or ...FileType::LsDynaKeyword
```
![Cube mesh](https://github.com/Tokarevart/polycr-mesh-generator/blob/master/images/polymesh_1.png)
# License
Copyright © 2018-2019 Tokarev Artem Alekseevich. All rights reserved.

Licensed under the [MIT License](/LICENSE).
