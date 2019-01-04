#include "onnx/onnx_pb.h"
#include <fstream>
#include <iostream>

using namespace std;
int main(int argc, char *argv[])
{

    //check input file
    if(argc < 2)
    {
        std::cout << "usage: onnx-parser <onnx file> \n";
        return 0;
    }
    std::string filename = argv[1];
    std::ifstream in(filename.c_str(),std::ios_base::binary);
    assert(in);

    //init onnx model
    onnx::ModelProto model;
    model.ParseFromIstream(&in);
    in.close();
    //std::cout << model.graph().input().size() << std::endl;
    
    cout << "*** Model Infomation *** " << std::endl;
    cout << "doc_string: " << model.doc_string() << endl; 
    cout << "domain: " << model.domain() << endl;
    cout << "ir_version: " << model.ir_version() << endl;
    cout << "model_version: " << model.model_version() << endl;
    cout << "producer_name: " << model.producer_name() << endl;
    cout << "producer_version: " << model.producer_version() << endl;
    
    char tmp[10];
    
    cout << "*** prepare print nodes info***" << endl;
    cin >> tmp;



    for(auto op : model.graph().node())
    {
        std::cout << "=======================" << std::endl;
        std::cout << "op name: " << op.name() << std::endl;
        
        cout << "  input: ";
        for(auto input:op.input())
        {
            cout << input << ", " ;
        }        
        cout << endl;
        
        cout << "  output: ";
        for(auto output:op.output())
        {
            cout << output << ", ";
        }
        cout << endl;

        cout << "  attribute: ";
        for(auto attr:op.attribute())
        {
            cout << attr.name() << endl ;

            cout << "    tensors: ";
            for(auto tensor:attr.tensors())
            {
                for(auto dim:tensor.dims())
                    cout << dim << ", " ;
            }

            
            
        }


        cout << endl;

        std::cout << std::endl;
    }
    




}

