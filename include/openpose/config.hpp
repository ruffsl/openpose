#ifndef OPENPOSE__CONFIG_HPP
#define OPENPOSE__CONFIG_HPP

#ifdef _MSC_VER
  #ifdef _WINDLL
    #ifdef openpose_EXPORTS
      #define OPENPOSE_API __declspec(dllexport)
    #else
      #define OPENPOSE_API __declspec(dllimport)
    #endif
  #else 
	#ifdef OPENPOSE_IMPORT_DLL
		#define OPENPOSE_API __declspec(dllimport)
	#else
		#define OPENPOSE_API
	#endif
  #endif
#else
  #define OPENPOSE_API
#endif


#endif