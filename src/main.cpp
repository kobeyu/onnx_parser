#include "onnx/onnx_pb.h"
#include <fstream>
#include <iostream>


int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        std::cout << "usage: onnx-parser <onnx file> \n";
        return 0;
    }
    std::string filename = argv[1];
    onnx::ModelProto model;
    std::ifstream in(filename.c_str(),std::ios_base::binary);

    assert(in);


    model.ParseFromIstream(&in);
    in.close();
    std::cout << model.graph().input().size() << std::endl;





}

