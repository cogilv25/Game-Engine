#ifdef NP_PLATFORM_WINDOWS
#ifdef NP_BUILD_DLL
	#define NP_API __declspec(dllexport)
#else
	#define NP_API __declspec(dllimport) 
//Comment needed to explain this as I can't remember why it's needed!
//I think it's because it's declared in the pch for NP and the client
//app doesn't have access to that so the compiler flags undeclared
//identifiers in headers that use the struct
	struct GLFWwindow;
#endif
#else
	#error "Negligent Precision only supports Windows at the moment"
#endif