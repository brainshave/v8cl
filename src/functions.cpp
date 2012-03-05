#include "v8cl.h"
#include "constants.h"

namespace v8cl {
//extern CL_API_ENTRY cl_int CL_API_CALL
//clRetainContext(cl_context /* context */) CL_API_SUFFIX__VERSION_1_0;

//extern CL_API_ENTRY cl_int CL_API_CALL
//clReleaseContext(cl_context /* context */) CL_API_SUFFIX__VERSION_1_0;

//extern CL_API_ENTRY cl_int CL_API_CALL
//clRetainCommandQueue(cl_command_queue /* command_queue */) CL_API_SUFFIX__VERSION_1_0;

//extern CL_API_ENTRY cl_int CL_API_CALL
//clReleaseCommandQueue(cl_command_queue /* command_queue */) CL_API_SUFFIX__VERSION_1_0;

//extern CL_API_ENTRY cl_int CL_API_CALL
//clRetainMemObject(cl_mem /* memobj */) CL_API_SUFFIX__VERSION_1_0;

//extern CL_API_ENTRY cl_int CL_API_CALL
//clReleaseMemObject(cl_mem /* memobj */) CL_API_SUFFIX__VERSION_1_0;

//extern CL_API_ENTRY cl_int CL_API_CALL
//clRetainSampler(cl_sampler /* sampler */) CL_API_SUFFIX__VERSION_1_0;

//extern CL_API_ENTRY cl_int CL_API_CALL
//clReleaseSampler(cl_sampler /* sampler */) CL_API_SUFFIX__VERSION_1_0;


//extern CL_API_ENTRY cl_int CL_API_CALL
//clRetainProgram(cl_program /* program */) CL_API_SUFFIX__VERSION_1_0;

//extern CL_API_ENTRY cl_int CL_API_CALL
//clReleaseProgram(cl_program /* program */) CL_API_SUFFIX__VERSION_1_0;

//extern CL_API_ENTRY cl_int CL_API_CALL
//clRetainKernel(cl_kernel    /* kernel */) CL_API_SUFFIX__VERSION_1_0;

//extern CL_API_ENTRY cl_int CL_API_CALL
//clReleaseKernel(cl_kernel   /* kernel */) CL_API_SUFFIX__VERSION_1_0;

//                                
///* Flush and Finish APIs */
//extern CL_API_ENTRY cl_int CL_API_CALL
//clFlush(cl_command_queue /* command_queue */) CL_API_SUFFIX__VERSION_1_0;

//extern CL_API_ENTRY cl_int CL_API_CALL
//clFinish(cl_command_queue /* command_queue */) CL_API_SUFFIX__VERSION_1_0;

  int32_t OneArgFn (void *f, vector<void*>& natives, vector<void*>& result) {
    int32_t (*clFn) (void* smth);
    *(void**) &clFn = f;

    void* smth = *(void**) natives[0];
    return clFn(smth);
  }

//extern CL_API_ENTRY cl_int CL_API_CALL 
//clGetPlatformInfo(cl_platform_id   /* platform */, 
//                  cl_platform_info /* param_name */,
//                  size_t           /* param_value_size */, 
//                  void *           /* param_value */,
//                  size_t *         /* param_value_size_ret */) CL_API_SUFFIX__VERSION_1_0;

//extern CL_API_ENTRY cl_int CL_API_CALL
//clGetDeviceInfo(cl_device_id    /* device */,
//                cl_device_info  /* param_name */, 
//                size_t          /* param_value_size */, 
//                void *          /* param_value */,
//                size_t *        /* param_value_size_ret */) CL_API_SUFFIX__VERSION_1_0;

    //extern CL_API_ENTRY cl_int CL_API_CALL
//clGetContextInfo(cl_context         /* context */, 
//                 cl_context_info    /* param_name */, 
//                 size_t             /* param_value_size */, 
//                 void *             /* param_value */, 
//                 size_t *           /* param_value_size_ret */) CL_API_SUFFIX__VERSION_1_0;

//extern CL_API_ENTRY cl_int CL_API_CALL
//clGetCommandQueueInfo(cl_command_queue      /* command_queue */,
//                      cl_command_queue_info /* param_name */,
//                      size_t                /* param_value_size */,
//                      void *                /* param_value */,
//                      size_t *              /* param_value_size_ret */) CL_API_SUFFIX__VERSION_1_0;

//                                    
//extern CL_API_ENTRY cl_int CL_API_CALL
//clGetMemObjectInfo(cl_mem           /* memobj */,
//                   cl_mem_info      /* param_name */, 
//                   size_t           /* param_value_size */,
//                   void *           /* param_value */,
//                   size_t *         /* param_value_size_ret */) CL_API_SUFFIX__VERSION_1_0;

//extern CL_API_ENTRY cl_int CL_API_CALL
//clGetImageInfo(cl_mem           /* image */,
//               cl_image_info    /* param_name */, 
//               size_t           /* param_value_size */,
//               void *           /* param_value */,
//               size_t *         /* param_value_size_ret */) CL_API_SUFFIX__VERSION_1_0;


//extern CL_API_ENTRY cl_int CL_API_CALL
//clGetSamplerInfo(cl_sampler         /* sampler */,
//                 cl_sampler_info    /* param_name */,
//                 size_t             /* param_value_size */,
//                 void *             /* param_value */,
//                 size_t *           /* param_value_size_ret */) CL_API_SUFFIX__VERSION_1_0;
//                            

//extern CL_API_ENTRY cl_int CL_API_CALL
//clGetProgramInfo(cl_program         /* program */,
//                 cl_program_info    /* param_name */,
//                 size_t             /* param_value_size */,
//                 void *             /* param_value */,
//                 size_t *           /* param_value_size_ret */) CL_API_SUFFIX__VERSION_1_0;

//extern CL_API_ENTRY cl_int CL_API_CALL
//clGetKernelInfo(cl_kernel       /* kernel */,
//                cl_kernel_info  /* param_name */,
//                size_t          /* param_value_size */,
//                void *          /* param_value */,
//                size_t *        /* param_value_size_ret */) CL_API_SUFFIX__VERSION_1_0;

  int32_t GetProgramBinaries (void *f, vector<void*>& natives, vector<void*>& result);

  int32_t GetInfo (void *f, vector<void*>& natives, vector<void*>& result) {
    uint32_t param_name = *(uint32_t*) natives[1];
    if (param_name == CL_PROGRAM_BINARIES) {
      return GetProgramBinaries(f, natives, result);
    }

    int32_t (*clGetInfo) (void*, uint32_t, size_t, void*, size_t*);
    *(void**) &clGetInfo = f;

    void *object = *(void**) natives[0];
    
    size_t size = 0;
    int32_t error = clGetInfo(object, param_name, 0, NULL, &size);
    if (error) return error;

    void *info = malloc(size);

    error = clGetInfo(object, param_name, size, info, NULL);
    if (error) {
      free(info);
      return error;
    }

    result.push_back(info);
    PushBackWrapped(result, size);
    return 0;
  }

  int32_t GetProgramBinaries (void *f, vector<void*>& natives, vector<void*>& result) {
    int32_t (*clGetInfo) (void*, uint32_t, size_t, void*, size_t*);
    *(void**) &clGetInfo = f;

    void *object = *(void**) natives[0];
    size_t size = 0;
    size_t error = clGetInfo(object, CL_PROGRAM_BINARY_SIZES, 0, NULL, &size);
    if (error) return error;

    size_t *sizes = (size_t*) malloc(size);
    error = clGetInfo(object, CL_PROGRAM_BINARY_SIZES, size, sizes, 0);
    if (error) {
      free(sizes);
      return 0;
    }

    size_t num_binaries = size / sizeof(size);
    unsigned char **binaries = (unsigned char**) malloc(num_binaries * sizeof(char**));
    for (size_t i = 0; i < num_binaries; ++i) {
      binaries[0] = (unsigned char*) malloc(sizes[i]);
    }

    error = clGetInfo(object, CL_PROGRAM_BINARIES, sizeof(char**), binaries, NULL);
    if (error) {
      for (size_t i = 0; i < num_binaries; ++i) {
        free(sizes);
        free(binaries[0]);
        free(binaries);
        return error;
      } 
    }

    result.push_back(sizes);
    PushBackWrapped(result, num_binaries);
    for (size_t i = 0; i < num_binaries; ++i) {
      result.push_back(binaries[i]);
    }

    free(binaries);
    return 0;
  }


//extern CL_API_ENTRY cl_int CL_API_CALL
//clGetProgramBuildInfo(cl_program            /* program */,
//                      cl_device_id          /* device */,
//                      cl_program_build_info /* param_name */,
//                      size_t                /* param_value_size */,
//                      void *                /* param_value */,
//                      size_t *              /* param_value_size_ret */) CL_API_SUFFIX__VERSION_1_0;
//                         

//extern CL_API_ENTRY cl_int CL_API_CALL
//clGetKernelWorkGroupInfo(cl_kernel                  /* kernel */,
//                         cl_device_id               /* device */,
//                         cl_kernel_work_group_info  /* param_name */,
//                         size_t                     /* param_value_size */,
//                         void *                     /* param_value */,
//                         size_t *                   /* param_value_size_ret */) CL_API_SUFFIX__VERSION_1_0;

  int32_t GetDependentInfo (void *f, vector<void*>& natives, vector<void*>& result) {
    int32_t (*clGetDependentInfo) (void*, void*, uint32_t, size_t, void*, size_t*);
    *(void**) &clGetDependentInfo = f;

    void *main = *(void**) natives[0];
    void *sub = *(void**) natives[1];
    uint32_t param_name = *(uint32_t*) natives[2];

    size_t size = 0;
    int32_t error = clGetDependentInfo(main, sub, param_name, 0, NULL, &size);
    if (error) return error;

    void *info = malloc(size);
    error = clGetDependentInfo(main, sub, param_name, size, info, NULL);
    if (error) {
      free(info);
      return error;
    }

    result.push_back(info);
    PushBackWrapped(result, size);
    return 0;
  }



  //extern CL_API_ENTRY cl_int CL_API_CALL
//clGetSupportedImageFormats(cl_context           /* context */,
//                           cl_mem_flags         /* flags */,
//                           cl_mem_object_type   /* image_type */,
//                           cl_uint              /* num_entries */,
//                           cl_image_format *    /* image_formats */,
//                           cl_uint *            /* num_image_formats */) CL_API_SUFFIX__VERSION_1_0;


  int32_t GetSupportedImageFormats (void *f, vector<void*>& natives, vector<void*>& result) {
    int32_t (*clGetSupportedImageFormats) (void*, uint64_t, uint32_t, uint32_t, cl_image_format*, uint32_t*);
    *(void**) &clGetSupportedImageFormats = f;

    void *context = *(void**) natives[0];
    uint32_t flags = *(uint32_t*) natives[1];
    uint32_t type = *(uint32_t*) natives[2];

    uint32_t size = 0;
    int32_t error = clGetSupportedImageFormats(context, flags, type, 0, NULL, &size);
    if (error) return error;

    cl_image_format *formats = (cl_image_format*) malloc(sizeof(cl_image_format) * size);
    error = clGetSupportedImageFormats(context, flags, type, size, formats, NULL);
    if (error) {
      free(formats);
      return error;
    }

    result.push_back(formats);
    PushBackWrapped(result, size);
    return 0;
  }

  //extern CL_API_ENTRY cl_int CL_API_CALL
//clGetPlatformIDs(cl_uint          /* num_entries */,
//                 cl_platform_id * /* platforms */,
//                 cl_uint *        /* num_platforms */) CL_API_SUFFIX__VERSION_1_0;
  
  int32_t GetPlatformIDs (void *f, vector<void*>& natives, vector<void*>& result) {
    int32_t (*clGetPlatformIDs) (size_t, void*, size_t*);
    *(void**) &clGetPlatformIDs = f;
    
    size_t size = 0;
    int32_t error = clGetPlatformIDs(0, NULL, &size);
    if (error) return error;
    
    void *platforms = malloc(sizeof(void*) * size);
    error = clGetPlatformIDs(size, platforms, NULL);
    if (error) {
      free(platforms);
      return error;
    }

    result.push_back(platforms);
    
    PushBackWrapped(result, size * sizeof(void*));
    // size_t *sizePtr = (size_t*) malloc(sizeof(size));
    // *sizePtr = size * sizeof(void*);
    // result.push_back(sizePtr);
    return 0;
  }

  //extern CL_API_ENTRY cl_int CL_API_CALL
//clGetDeviceIDs(cl_platform_id   /* platform */,
//               cl_device_type   /* device_type */, 
//               cl_uint          /* num_entries */, 
//               cl_device_id *   /* devices */, 
//               cl_uint *        /* num_devices */) CL_API_SUFFIX__VERSION_1_0;
  
  int32_t GetDeviceIDs (void *f, vector<void*>& natives, vector<void*>& result) {
    int32_t (*clGetDeviceIDs) (void*, uint64_t, size_t, void*, size_t*);
    *(void**) &clGetDeviceIDs = f;

    void *platform = *(void**) natives[0];
    // uint32_t because js doesn't support uint64_t
    uint32_t device_type = *(uint32_t*) natives[1];

    size_t size = 0;
    int32_t error = clGetDeviceIDs(platform, device_type, 0, NULL, &size);
    if (error) return error;
    
    void *devices = malloc(sizeof(void*) * size);
    error = clGetDeviceIDs(platform, device_type, size, devices, NULL);
    if (error) {
      free(devices);
      return error;
    }

    result.push_back(devices);
    
    PushBackWrapped(result, size * sizeof(void*));
    // size_t *sizeHolder = (size_t*) malloc(sizeof(size));
    // *sizeHolder = size * sizeof(void*);
    // result.push_back(sizeHolder);
    return 0;
  }

  //extern CL_API_ENTRY cl_context CL_API_CALL
//clCreateContext(const cl_context_properties * /* properties */,
//                cl_uint                       /* num_devices */,
//                const cl_device_id *          /* devices */,
//                void (CL_CALLBACK * /* pfn_notify */)(const char *, const void *, size_t, void *),
//                void *                        /* user_data */,
//                cl_int *                      /* errcode_ret */) CL_API_SUFFIX__VERSION_1_0;

  int32_t CreateContext (void *f, vector<void*>& natives, vector<void*>& result) {
    void* (*clCreateContext) (intptr_t*, uint32_t, void*, void*, void*, int32_t*);
    *(void**) &clCreateContext = f;
    
    intptr_t *properties = (intptr_t*) natives[0];
      
    void *devices = natives[1];
    size_t size = *(size_t*) natives[2];

    // TODO: implement user_data as typed array?

    int32_t error = 0;
    void *context = clCreateContext(properties, size, devices, NULL, NULL, &error);
    if (error) {
      return error;
    }

    PushBackWrapped(result, context);
    // void **holder = (void**) malloc(sizeof(void*));
    // *holder = context;
    // result.push_back(holder);
    return 0;
  }

//extern CL_API_ENTRY cl_context CL_API_CALL
//clCreateContextFromType(const cl_context_properties * /* properties */,
//                        cl_device_type                /* device_type */,
//                        void (CL_CALLBACK *     /* pfn_notify*/ )(const char *, const void *, size_t, void *),
//                        void *                        /* user_data */,
//                        cl_int *                      /* errcode_ret */) CL_API_SUFFIX__VERSION_1_0;

  int32_t CreateContextFromType (void *f, vector<void*>& natives, vector<void*>& result) {
    void* (*clCreateContextFromType) (intptr_t*, uint64_t, void*, void*, int32_t*);
    *(void**) &clCreateContextFromType = f;

    intptr_t *properties = (intptr_t*) natives[0];
       
    uint32_t device_type = *(uint32_t*) natives[1];
   
    int32_t error = 0;
    // sprawdzic w zad801
    void *context = clCreateContextFromType(properties, device_type, NULL, NULL, &error);
    if (error) {
      return error;
    }

    PushBackWrapped(result, context);
    // void **holder = (void**) malloc(sizeof(void*));
    // *holder = context;
    // result.push_back(holder);
    return 0;
  }

///* Command Queue APIs */
//extern CL_API_ENTRY cl_command_queue CL_API_CALL
//clCreateCommandQueue(cl_context                     /* context */, 
//                     cl_device_id                   /* device */, 
//                     cl_command_queue_properties    /* properties */,
//                     cl_int *                       /* errcode_ret */) CL_API_SUFFIX__VERSION_1_0;

  int32_t CreateCommandQueue (void *f, vector<void*>& natives, vector<void*>& result) {
    void* (*clCreateCommandQueue) (void*, void*, uint64_t, int32_t*);
    *(void**) &clCreateCommandQueue = f;

    void *context = *(void**) natives[0];
    void *device = *(void**) natives[1];
    uint32_t flags = *(uint32_t*) natives[2];

    int32_t error = 0;
    void *queue = clCreateCommandQueue(context, device, flags, &error);
    if (error) {
      return error;
    }

    PushBackWrapped(result, queue);
    // void **holder = (void**) malloc(sizeof(void*));
    // *holder = queue;
    // result.push_back(holder);
    return 0;
  }


///* Memory Object APIs */
//extern CL_API_ENTRY cl_mem CL_API_CALL
//clCreateBuffer(cl_context   /* context */,
//               cl_mem_flags /* flags */,
//               size_t       /* size */,
//               void *       /* host_ptr */,
//               cl_int *     /* errcode_ret */) CL_API_SUFFIX__VERSION_1_0;
  int32_t CreateBuffer (void *f, vector<void*>& natives, vector<void*>& result) {
    void* (*clCreateBuffer) (void*, uint64_t, size_t, void*, int32_t*);
    *(void**) &clCreateBuffer = f;

    void *context = *(void**) natives[0];
    uint32_t flags = *(uint32_t*) natives[1];
    size_t size = *(size_t*) natives[2];
    void *host_ptr = NULL; //*(void**) natives[3]; // TODO: Native array

    int32_t error = 0;
    void *mem = clCreateBuffer(context, flags, size, host_ptr, &error);
    if (error) {
      return error;
    }

    PushBackWrapped(result, mem);
    return 0;
  }

//extern CL_API_ENTRY cl_mem CL_API_CALL
//clCreateSubBuffer(cl_mem                   /* buffer */,
//                  cl_mem_flags             /* flags */,
//                  cl_buffer_create_type    /* buffer_create_type */,
//                  const void *             /* buffer_create_info */,
//                  cl_int *                 /* errcode_ret */) CL_API_SUFFIX__VERSION_1_1;
  int32_t CreateSubBuffer (void *f, vector<void*>& natives, vector<void*>& result) {
    void* (*clCreateSubBuffer) (void*, uint64_t, uint32_t, void*, int32_t*);
    *(void**) &clCreateSubBuffer = f;

    void *mem = *(void**) natives[0];
    uint32_t flags = *(uint32_t*) natives[1];
    uint32_t create_type = *(uint32_t*) natives[2];
    cl_buffer_region *create_info = (cl_buffer_region*) natives[3];

    int32_t error = 0;
    void *submem = clCreateSubBuffer(mem, flags, create_type, create_info, &error);
    if (error) {
      return error;
    }

    PushBackWrapped(result, submem);
    return 0;
  }


//extern CL_API_ENTRY cl_mem CL_API_CALL
//clCreateImage2D(cl_context              /* context */,
//                cl_mem_flags            /* flags */,
//                const cl_image_format * /* image_format */,
//                size_t                  /* image_width */,
//                size_t                  /* image_height */,
//                size_t                  /* image_row_pitch */, 
//                void *                  /* host_ptr */,
//                cl_int *                /* errcode_ret */) CL_API_SUFFIX__VERSION_1_0;
  int32_t CreateImage2D (void *f, vector<void*>& natives, vector<void*>& result) {
    void* (*clCreateImage2D) (void*, uint64_t, cl_image_format*, size_t, size_t, size_t, void*, int32_t*);
    *(void**) &clCreateImage2D = f;

    void *context = *(void**) natives[0];
    uint32_t flags = *(uint32_t*) natives[1];
    cl_image_format *image_format = (cl_image_format*) natives[2];
    size_t width = *(size_t*) natives[3];
    size_t height = *(size_t*) natives[4];
    size_t row_pitch = 0; // TODO: depends on host_ptr // *(size_t*) natives[5];
    void *host_ptr = NULL; // TODO: Native array

    int32_t error = 0;
    void *mem = clCreateImage2D(context, flags, image_format, width, height, row_pitch, host_ptr, &error);
    if (error) {
      return error;
    }

    PushBackWrapped(result, mem);
    return 0;
  }

//                        
//extern CL_API_ENTRY cl_mem CL_API_CALL
//clCreateImage3D(cl_context              /* context */,
//                cl_mem_flags            /* flags */,
//                const cl_image_format * /* image_format */,
//                size_t                  /* image_width */, 
//                size_t                  /* image_height */,
//                size_t                  /* image_depth */, 
//                size_t                  /* image_row_pitch */, 
//                size_t                  /* image_slice_pitch */, 
//                void *                  /* host_ptr */,
//                cl_int *                /* errcode_ret */) CL_API_SUFFIX__VERSION_1_0;
  int32_t CreateImage3D (void *f, vector<void*>& natives, vector<void*>& result) {
    void* (*clCreateImage3D) (void*, uint64_t, cl_image_format*, size_t, size_t, size_t, size_t, size_t, void*, int32_t*);
    *(void**) &clCreateImage3D = f;

    void *context = *(void**) natives[0];
    uint32_t flags = *(uint32_t*) natives[1];
    cl_image_format *image_format = (cl_image_format*) natives[2];
    size_t width = *(size_t*) natives[3];
    size_t height = *(size_t*) natives[4];
    size_t depth = *(size_t*) natives[5];
    size_t row_pitch = 0; // TODO: depends on host_ptr // *(size_t*) natives[6];
    size_t slice_pitch = 0; // TODO: depends on host_ptr // *(size_t*) natives[7];
    void *host_ptr = NULL; // TODO: Native array

    int32_t error = 0;
    void *mem = clCreateImage3D(context, flags, image_format, width, height, depth, row_pitch, slice_pitch, host_ptr, &error);
    if (error) {
      return error;
    }

    PushBackWrapped(result, mem);
    return 0;
  }


///* Sampler APIs  */
//extern CL_API_ENTRY cl_sampler CL_API_CALL
//clCreateSampler(cl_context          /* context */,
//                cl_bool             /* normalized_coords */, 
//                cl_addressing_mode  /* addressing_mode */, 
//                cl_filter_mode      /* filter_mode */,
//                cl_int *            /* errcode_ret */) CL_API_SUFFIX__VERSION_1_0;
  int32_t CreateSampler (void *f, vector<void*>& natives, vector<void*>& result) {
    void* (*clCreateSampler) (void*, uint32_t, uint32_t, uint32_t, int32_t*);
    *(void**) &clCreateSampler = f;

    void *context = *(void**) natives[0];
    uint32_t norm_coords = *(uint32_t*) natives[1];
    uint32_t addressing_mode = *(uint32_t*) natives[2];
    uint32_t filter_mode = *(uint32_t*) natives[3];

    int32_t error = 0;
    void *sampler = clCreateSampler(context, norm_coords, addressing_mode, filter_mode, &error);
    if (error) return error;

    PushBackWrapped(result, sampler);
    return 0;
  }

///* Program Object APIs  */
//extern CL_API_ENTRY cl_program CL_API_CALL
//clCreateProgramWithSource(cl_context        /* context */,
//                          cl_uint           /* count */,
//                          const char **     /* strings */,
//                          const size_t *    /* lengths */,
//                          cl_int *          /* errcode_ret */) CL_API_SUFFIX__VERSION_1_0;
  int32_t CreateProgramWithSource (void *f, vector<void*>& natives, vector<void*>& result) {
    void* (*clCreateProgramWithSource) (void*, uint32_t, char**, size_t*, int32_t*);
    *(void**) &clCreateProgramWithSource = f;

    void *context = *(void**) natives[0];
    char *code = (char*) natives[1];
    size_t size = *(size_t*) natives[2];

    int32_t error = 0;
    void* program = clCreateProgramWithSource(context, 1, &code, &size, &error);
    if (error) return error;

    PushBackWrapped(result, program);
    return 0;
  }


//extern CL_API_ENTRY cl_int CL_API_CALL
//clBuildProgram(cl_program           /* program */,
//               cl_uint              /* num_devices */,
//               const cl_device_id * /* device_list */,
//               const char *         /* options */, 
//               void (CL_CALLBACK *  /* pfn_notify */)(cl_program /* program */, void * /* user_data */),
//               void *               /* user_data */) CL_API_SUFFIX__VERSION_1_0;
  int32_t BuildProgram (void *f, vector<void*>& natives, vector<void*>& result) {
    int32_t (*clBuildProgram) (void*, uint32_t, void*, char*, void*, void*);
    *(void**) &clBuildProgram = f;

    void *program = *(void**) natives[0];
    void *devices = natives[1];
    size_t num_devices = *(size_t*) natives[2];
    char *options = (char*) natives[3];
    // natives[4] would is the size of options

    uint32_t error = clBuildProgram(program, num_devices, devices, options, NULL, NULL);
    return error;
  }

 
///* Kernel Object APIs */
//extern CL_API_ENTRY cl_kernel CL_API_CALL
//clCreateKernel(cl_program      /* program */,
//               const char *    /* kernel_name */,
//               cl_int *        /* errcode_ret */) CL_API_SUFFIX__VERSION_1_0;
  int32_t CreateKernel (void *f, vector<void*>& natives, vector<void*>& result) {
    void* (*clCreateKernel) (void*, char*, int32_t*);
    *(void**) &clCreateKernel = f;

    void *program = *(void**) natives[0];
    char *name = (char*) natives[1];

    int32_t error = 0;
    void *kernel = clCreateKernel(program, name, &error);
    if (error) return error;

    PushBackWrapped(result, kernel);
    return 0;
  }

//extern CL_API_ENTRY cl_int CL_API_CALL
//clCreateKernelsInProgram(cl_program     /* program */,
//                         cl_uint        /* num_kernels */,
//                         cl_kernel *    /* kernels */,
//                         cl_uint *      /* num_kernels_ret */) CL_API_SUFFIX__VERSION_1_0;
  int32_t CreateKernelsInProgram (void *f, vector<void*>& natives, vector<void*>& result) {
    int32_t (*clCreateKernelsInProgram) (void*, uint32_t, void*, uint32_t*);
    *(void**) &clCreateKernelsInProgram = f;

    void *program = *(void**) natives[0];

    uint32_t size = 0;
    int32_t error = clCreateKernelsInProgram(program, 0, NULL, &size);
    if (error) return error;

    void *kernels = malloc(size);
    error = clCreateKernelsInProgram(program, size, kernels, 0);
    if (error) {
      free(kernels);
      return error;
    }

    result.push_back(kernels);
    PushBackWrapped(result, size * sizeof(void*));
    return 0;
  }


//extern CL_API_ENTRY cl_int CL_API_CALL
//clSetKernelArg(cl_kernel    /* kernel */,
//               cl_uint      /* arg_index */,
//               size_t       /* arg_size */,
//               const void * /* arg_value */) CL_API_SUFFIX__VERSION_1_0;
  int32_t SetKernelArg (void *f, vector<void*>& natives, vector<void*>& result) {
    int32_t (*clSetKernelArg) (void*, uint32_t, size_t, void*);
    *(void**) &clSetKernelArg = f;

    void *kernel = *(void**) natives[0];
    uint32_t index = *(uint32_t*) natives[1];
    size_t size = *(size_t*) natives[2];
    void *value = natives[3];
    size_t valueSize = *(size_t*) natives[4];
    if (valueSize) {
      if (size > valueSize) size = valueSize;
      value = *(void**) value;
    }
    
    return clSetKernelArg(kernel, index, size, value);
  }

///* Enqueued Commands APIs */
//extern CL_API_ENTRY cl_int CL_API_CALL
//clEnqueueReadBuffer(cl_command_queue    /* command_queue */,
//                    cl_mem              /* buffer */,
//                    cl_bool             /* blocking_read */,
//                    size_t              /* offset */,
//                    size_t              /* cb */, 
//                    void *              /* ptr */,
//                    cl_uint             /* num_events_in_wait_list */,
//                    const cl_event *    /* event_wait_list */,
//                    cl_event *          /* event */) CL_API_SUFFIX__VERSION_1_0;
  //extern CL_API_ENTRY cl_int CL_API_CALL
//clEnqueueWriteBuffer(cl_command_queue   /* command_queue */, 
//                     cl_mem             /* buffer */, 
//                     cl_bool            /* blocking_write */, 
//                     size_t             /* offset */, 
//                     size_t             /* cb */, 
//                     const void *       /* ptr */, 
//                     cl_uint            /* num_events_in_wait_list */, 
//                     const cl_event *   /* event_wait_list */, 
//                     cl_event *         /* event */) CL_API_SUFFIX__VERSION_1_0;

  int32_t EnqueueReadOrWriteBuffer (void *f, vector<void*>& natives, vector<void*>& result) {
    int32_t (*clEnqueueReadOrWriteBuffer) (void*, void*, uint32_t, size_t, size_t, void*, uint32_t, void*, void*);
    *(void**) &clEnqueueReadOrWriteBuffer = f;

    void *queue = *(void**) natives[0];
    void *mem = *(void**) natives[1];
    uint32_t offset = *(uint32_t*) natives[2];
    void *ptr = *(void**) natives[3];
    size_t size = *(size_t*) natives[4];

    return clEnqueueReadOrWriteBuffer(queue, mem, 0 /* false */, offset, size, ptr, 0, NULL, NULL);
  }

//extern CL_API_ENTRY cl_int CL_API_CALL
//clEnqueueNDRangeKernel(cl_command_queue /* command_queue */,
//                       cl_kernel        /* kernel */,
//                       cl_uint          /* work_dim */,
//                       const size_t *   /* global_work_offset */,
//                       const size_t *   /* global_work_size */,
//                       const size_t *   /* local_work_size */,
//                       cl_uint          /* num_events_in_wait_list */,
//                       const cl_event * /* event_wait_list */,
//                       cl_event *       /* event */) CL_API_SUFFIX__VERSION_1_0;
  int32_t EnqueueNDRangeKernel (void *f, vector<void*>& natives, vector<void*>& result) {
    int32_t (*clEnqueueNDRangeKernel) (void*, void*, uint32_t, size_t*, size_t*, size_t*, uint32_t, void*, void*);
    *(void**) &clEnqueueNDRangeKernel = f;

    void *queue = *(void**) natives[0];
    void *kernel = *(void**) natives[1];
    size_t *global_work_offset = (size_t*) natives[2];
    size_t *global_work_size = (size_t*) natives[4];
    size_t *local_work_size = (size_t*) natives[6];
    uint32_t work_dim1 = *(uint32_t*) natives[3];
    uint32_t work_dim2 = *(uint32_t*) natives[5];
    uint32_t work_dim3 = *(uint32_t*) natives[7];
    
    if (work_dim1 == 0) {
      global_work_offset = NULL;
    }
    if (work_dim1 == 0 || work_dim2 < work_dim1) work_dim1 = work_dim2;
    if (work_dim1 == 0 || work_dim3 < work_dim1) work_dim1 = work_dim3;

    if (work_dim1) {
      return clEnqueueNDRangeKernel(queue, kernel, work_dim1, global_work_offset, global_work_size, local_work_size, 0, NULL, NULL);
    } else {
      return CL_INVALID_WORK_DIMENSION;
    }
  }

//                            
//extern CL_API_ENTRY cl_int CL_API_CALL
//clEnqueueReadBufferRect(cl_command_queue    /* command_queue */,
//                        cl_mem              /* buffer */,
//                        cl_bool             /* blocking_read */,
//                        const size_t *      /* buffer_origin */,
//                        const size_t *      /* host_origin */, 
//                        const size_t *      /* region */,
//                        size_t              /* buffer_row_pitch */,
//                        size_t              /* buffer_slice_pitch */,
//                        size_t              /* host_row_pitch */,
//                        size_t              /* host_slice_pitch */,                        
//                        void *              /* ptr */,
//                        cl_uint             /* num_events_in_wait_list */,
//                        const cl_event *    /* event_wait_list */,
//                        cl_event *          /* event */) CL_API_SUFFIX__VERSION_1_1;
//                            

//                            
//extern CL_API_ENTRY cl_int CL_API_CALL
//clEnqueueWriteBufferRect(cl_command_queue    /* command_queue */,
//                         cl_mem              /* buffer */,
//                         cl_bool             /* blocking_write */,
//                         const size_t *      /* buffer_origin */,
//                         const size_t *      /* host_origin */, 
//                         const size_t *      /* region */,
//                         size_t              /* buffer_row_pitch */,
//                         size_t              /* buffer_slice_pitch */,
//                         size_t              /* host_row_pitch */,
//                         size_t              /* host_slice_pitch */,                        
//                         const void *        /* ptr */,
//                         cl_uint             /* num_events_in_wait_list */,
//                         const cl_event *    /* event_wait_list */,
//                         cl_event *          /* event */) CL_API_SUFFIX__VERSION_1_1;
//                            
//extern CL_API_ENTRY cl_int CL_API_CALL
//clEnqueueCopyBuffer(cl_command_queue    /* command_queue */, 
//                    cl_mem              /* src_buffer */,
//                    cl_mem              /* dst_buffer */, 
//                    size_t              /* src_offset */,
//                    size_t              /* dst_offset */,
//                    size_t              /* cb */, 
//                    cl_uint             /* num_events_in_wait_list */,
//                    const cl_event *    /* event_wait_list */,
//                    cl_event *          /* event */) CL_API_SUFFIX__VERSION_1_0;
//                            
//extern CL_API_ENTRY cl_int CL_API_CALL
//clEnqueueCopyBufferRect(cl_command_queue    /* command_queue */, 
//                        cl_mem              /* src_buffer */,
//                        cl_mem              /* dst_buffer */, 
//                        const size_t *      /* src_origin */,
//                        const size_t *      /* dst_origin */,
//                        const size_t *      /* region */, 
//                        size_t              /* src_row_pitch */,
//                        size_t              /* src_slice_pitch */,
//                        size_t              /* dst_row_pitch */,
//                        size_t              /* dst_slice_pitch */,
//                        cl_uint             /* num_events_in_wait_list */,
//                        const cl_event *    /* event_wait_list */,
//                        cl_event *          /* event */) CL_API_SUFFIX__VERSION_1_1;
//                            
//extern CL_API_ENTRY cl_int CL_API_CALL
//clEnqueueReadImage(cl_command_queue     /* command_queue */,
//                   cl_mem               /* image */,
//                   cl_bool              /* blocking_read */, 
//                   const size_t *       /* origin[3] */,
//                   const size_t *       /* region[3] */,
//                   size_t               /* row_pitch */,
//                   size_t               /* slice_pitch */, 
//                   void *               /* ptr */,
//                   cl_uint              /* num_events_in_wait_list */,
//                   const cl_event *     /* event_wait_list */,
//                   cl_event *           /* event */) CL_API_SUFFIX__VERSION_1_0;

//extern CL_API_ENTRY cl_int CL_API_CALL
//clEnqueueWriteImage(cl_command_queue    /* command_queue */,
//                    cl_mem              /* image */,
//                    cl_bool             /* blocking_write */, 
//                    const size_t *      /* origin[3] */,
//                    const size_t *      /* region[3] */,
//                    size_t              /* input_row_pitch */,
//                    size_t              /* input_slice_pitch */, 
//                    const void *        /* ptr */,
//                    cl_uint             /* num_events_in_wait_list */,
//                    const cl_event *    /* event_wait_list */,
//                    cl_event *          /* event */) CL_API_SUFFIX__VERSION_1_0;

//extern CL_API_ENTRY cl_int CL_API_CALL
//clEnqueueCopyImage(cl_command_queue     /* command_queue */,
//                   cl_mem               /* src_image */,
//                   cl_mem               /* dst_image */, 
//                   const size_t *       /* src_origin[3] */,
//                   const size_t *       /* dst_origin[3] */,
//                   const size_t *       /* region[3] */, 
//                   cl_uint              /* num_events_in_wait_list */,
//                   const cl_event *     /* event_wait_list */,
//                   cl_event *           /* event */) CL_API_SUFFIX__VERSION_1_0;

//extern CL_API_ENTRY cl_int CL_API_CALL
//clEnqueueCopyImageToBuffer(cl_command_queue /* command_queue */,
//                           cl_mem           /* src_image */,
//                           cl_mem           /* dst_buffer */, 
//                           const size_t *   /* src_origin[3] */,
//                           const size_t *   /* region[3] */, 
//                           size_t           /* dst_offset */,
//                           cl_uint          /* num_events_in_wait_list */,
//                           const cl_event * /* event_wait_list */,
//                           cl_event *       /* event */) CL_API_SUFFIX__VERSION_1_0;

//extern CL_API_ENTRY cl_int CL_API_CALL
//clEnqueueCopyBufferToImage(cl_command_queue /* command_queue */,
//                           cl_mem           /* src_buffer */,
//                           cl_mem           /* dst_image */, 
//                           size_t           /* src_offset */,
//                           const size_t *   /* dst_origin[3] */,
//                           const size_t *   /* region[3] */, 
//                           cl_uint          /* num_events_in_wait_list */,
//                           const cl_event * /* event_wait_list */,
//                           cl_event *       /* event */) CL_API_SUFFIX__VERSION_1_0;

//extern CL_API_ENTRY void * CL_API_CALL
//clEnqueueMapBuffer(cl_command_queue /* command_queue */,
//                   cl_mem           /* buffer */,
//                   cl_bool          /* blocking_map */, 
//                   cl_map_flags     /* map_flags */,
//                   size_t           /* offset */,
//                   size_t           /* cb */,
//                   cl_uint          /* num_events_in_wait_list */,
//                   const cl_event * /* event_wait_list */,
//                   cl_event *       /* event */,
//                   cl_int *         /* errcode_ret */) CL_API_SUFFIX__VERSION_1_0;

//extern CL_API_ENTRY void * CL_API_CALL
//clEnqueueMapImage(cl_command_queue  /* command_queue */,
//                  cl_mem            /* image */, 
//                  cl_bool           /* blocking_map */, 
//                  cl_map_flags      /* map_flags */, 
//                  const size_t *    /* origin[3] */,
//                  const size_t *    /* region[3] */,
//                  size_t *          /* image_row_pitch */,
//                  size_t *          /* image_slice_pitch */,
//                  cl_uint           /* num_events_in_wait_list */,
//                  const cl_event *  /* event_wait_list */,
//                  cl_event *        /* event */,
//                  cl_int *          /* errcode_ret */) CL_API_SUFFIX__VERSION_1_0;

//extern CL_API_ENTRY cl_int CL_API_CALL
//clEnqueueUnmapMemObject(cl_command_queue /* command_queue */,
//                        cl_mem           /* memobj */,
//                        void *           /* mapped_ptr */,
//                        cl_uint          /* num_events_in_wait_list */,
//                        const cl_event *  /* event_wait_list */,
//                        cl_event *        /* event */) CL_API_SUFFIX__VERSION_1_0;

//extern CL_API_ENTRY cl_int CL_API_CALL
//clEnqueueTask(cl_command_queue  /* command_queue */,
//              cl_kernel         /* kernel */,
//              cl_uint           /* num_events_in_wait_list */,
//              const cl_event *  /* event_wait_list */,
//              cl_event *        /* event */) CL_API_SUFFIX__VERSION_1_0;

//extern CL_API_ENTRY cl_int CL_API_CALL
//clEnqueueNativeKernel(cl_command_queue  /* command_queue */,
//					  void (*user_func)(void *), 
//                      void *            /* args */,
//                      size_t            /* cb_args */, 
//                      cl_uint           /* num_mem_objects */,
//                      const cl_mem *    /* mem_list */,
//                      const void **     /* args_mem_loc */,
//                      cl_uint           /* num_events_in_wait_list */,
//                      const cl_event *  /* event_wait_list */,
//                      cl_event *        /* event */) CL_API_SUFFIX__VERSION_1_0;

//extern CL_API_ENTRY cl_int CL_API_CALL
//clEnqueueMarker(cl_command_queue    /* command_queue */,
//                cl_event *          /* event */) CL_API_SUFFIX__VERSION_1_0;

//extern CL_API_ENTRY cl_int CL_API_CALL
//clEnqueueWaitForEvents(cl_command_queue /* command_queue */,
//                       cl_uint          /* num_events */,
//                       const cl_event * /* event_list */) CL_API_SUFFIX__VERSION_1_0;

//extern CL_API_ENTRY cl_int CL_API_CALL
//clEnqueueBarrier(cl_command_queue /* command_queue */) CL_API_SUFFIX__VERSION_1_0;

///* Extension function access
// *
// * Returns the extension function address for the given function name,
// * or NULL if a valid function can not be found.  The client must
// * check to make sure the address is not NULL, before using or 
// * calling the returned function address.
// */
//extern CL_API_ENTRY void * CL_API_CALL clGetExtensionFunctionAddress(const char * /* func_name */) CL_API_SUFFIX__VERSION_1_0;


//extern CL_API_ENTRY cl_int CL_API_CALL
//clSetMemObjectDestructorCallback(  cl_mem /* memobj */, 
//                                    void (CL_CALLBACK * /*pfn_notify*/)( cl_mem /* memobj */, void* /*user_data*/), 
//                                    void * /*user_data */ )             CL_API_SUFFIX__VERSION_1_1;  

    //extern CL_API_ENTRY cl_program CL_API_CALL
//clCreateProgramWithBinary(cl_context                     /* context */,
//                          cl_uint                        /* num_devices */,
//                          const cl_device_id *           /* device_list */,
//                          const size_t *                 /* lengths */,
//                          const unsigned char **         /* binaries */,
//                          cl_int *                       /* binary_status */,
//                          cl_int *                       /* errcode_ret */) CL_API_SUFFIX__VERSION_1_0;


//extern CL_API_ENTRY cl_int CL_API_CALL
//clUnloadCompiler(void) CL_API_SUFFIX__VERSION_1_0;



///* Event Object APIs  */
//extern CL_API_ENTRY cl_int CL_API_CALL
//clWaitForEvents(cl_uint             /* num_events */,
//                const cl_event *    /* event_list */) CL_API_SUFFIX__VERSION_1_0;

//extern CL_API_ENTRY cl_int CL_API_CALL
//clGetEventInfo(cl_event         /* event */,
//               cl_event_info    /* param_name */,
//               size_t           /* param_value_size */,
//               void *           /* param_value */,
//               size_t *         /* param_value_size_ret */) CL_API_SUFFIX__VERSION_1_0;
//                            
//extern CL_API_ENTRY cl_event CL_API_CALL
//clCreateUserEvent(cl_context    /* context */,
//                  cl_int *      /* errcode_ret */) CL_API_SUFFIX__VERSION_1_1;               
//                            
//extern CL_API_ENTRY cl_int CL_API_CALL
//clRetainEvent(cl_event /* event */) CL_API_SUFFIX__VERSION_1_0;

//extern CL_API_ENTRY cl_int CL_API_CALL
//clReleaseEvent(cl_event /* event */) CL_API_SUFFIX__VERSION_1_0;

//extern CL_API_ENTRY cl_int CL_API_CALL
//clSetUserEventStatus(cl_event   /* event */,
//                     cl_int     /* execution_status */) CL_API_SUFFIX__VERSION_1_1;
//                     
//extern CL_API_ENTRY cl_int CL_API_CALL
//clSetEventCallback( cl_event    /* event */,
//                    cl_int      /* command_exec_callback_type */,
//                    void (CL_CALLBACK * /* pfn_notify */)(cl_event, cl_int, void *),
//                    void *      /* user_data */) CL_API_SUFFIX__VERSION_1_1;

///* Profiling APIs  */
//extern CL_API_ENTRY cl_int CL_API_CALL
//clGetEventProfilingInfo(cl_event            /* event */,
//                        cl_profiling_info   /* param_name */,
//                        size_t              /* param_value_size */,
//                        void *              /* param_value */,
//                        size_t *            /* param_value_size_ret */) CL_API_SUFFIX__VERSION_1_0;

}
