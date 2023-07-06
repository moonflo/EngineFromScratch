ispc --arch=x86-64 --target=host -o CrossProduct.o -I ./ -h ./include/CrossProduct.h ./ispc/CrossProduct.ispc
ispc --arch=x86-64 --target=host -o DotProduct.o -I ./ -h ./include/DotProduct.h ./ispc/DotProduct.ispc
ispc --arch=x86-64 --target=host -o MulByElement.o -I ./ -h ./include/MulByElement.h ./ispc/MulByElement.ispc
ispc --arch=x86-64 --target=host -o Transpose.o -I ./ -h ./include/Transpose.h ./ispc/Transpose.ispc
ispc --arch=x86-64 --target=host -o Normalize.o -I ./ -h ./include/Normalize.h ./ispc/Normalize.ispc
ispc --arch=x86-64 --target=host -o Transform.o -I ./ -h ./include/Transform.h ./ispc/Transform.ispc
ispc --arch=x86-64 --target=host -o AddByElement.o -I ./ -h ./include/AddByElement.h ./ispc/AddByElement.ispc
ispc --arch=x86-64 --target=host -o SubByElement.o -I ./ -h ./include/SubByElement.h ./ispc/SubByElement.ispc