#! /bin/bash

g++ prog.cpp class.cpp raytracer.cpp ray_in_a_box/tracebox.cpp -framework Accelerate

if [ -f a.out ]; then
    ./a.out
fi