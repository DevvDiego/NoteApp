#include <fstream>
#include <iostream>

class FileManager {
private:
    static std::ifstream input;
    static std::ofstream output;

public:


    static bool WriteTo(std::string fileName, std::string path, std::string content){
        try{
            //flags work to not create a new file when called output.open
            output.open(fileName + ".txt", std::ios::in | std::ios::out);
            if( !output.is_open() ){
                throw std::runtime_error("File not found on opening\n\n");
                
            }

            output << fileName;
            output.close();

        }catch(std::exception &e){
            std::cerr<< "Error, type: " << e.what() << std::endl;

        }


    }

    static bool ReadFrom(std::string fileName, std::string path){
        try{
            input.open(fileName + ".txt");
            if( !input.is_open() ){
                throw std::runtime_error("File not found on writing\n\n");

            }
            
        }catch(std::exception &e){
            std::cerr<< "Error, type: " << e.what() << std::endl;

        }
    }

    static bool Create(std::string fileName){
        return fileExists(fileName);

    }

    static bool Update(std::string fileName, std::string path){
        
    }

    static bool Delete(std::string fileName, std::string path){

    }

    // static bool SearchForFile(std::string fileName, std::string path){

    // }


    //auxiliar methods

    /**
     * returns true if exists, false if doesnt exists
     */
    static bool fileExists(std::string fileName){
        try{
            //flags work to not create a new file when called output.open
            output.open(fileName + ".txt", std::ios::in | std::ios::out);
            
            if( !output.is_open() ){
                std::cerr<<"\n\nFile does not exists\n\n";

                return false;

            }else{
                std::cout<<"\n\nFile exists\n\n";
                output.close();

                return true;

            }

            
        }catch(std::exception &e){
            std::cerr<< "Error, type: " << e.what() << std::endl;

            return false;

        }
    }

};

//initialize static members
std::ifstream FileManager::input;
std::ofstream FileManager::output;
