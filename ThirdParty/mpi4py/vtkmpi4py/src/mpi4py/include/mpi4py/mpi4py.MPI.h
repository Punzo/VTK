/* Generated by Cython 0.29.36 */

#ifndef __PYX_HAVE__mpi4py__MPI
#define __PYX_HAVE__mpi4py__MPI

#include "Python.h"
struct PyMPIDatatypeObject;
struct PyMPIStatusObject;
struct PyMPIRequestObject;
struct PyMPIPrequestObject;
struct PyMPIGrequestObject;
struct PyMPIMessageObject;
struct PyMPIOpObject;
struct PyMPIGroupObject;
struct PyMPIInfoObject;
struct PyMPIErrhandlerObject;
struct PyMPICommObject;
struct PyMPIIntracommObject;
struct PyMPITopocommObject;
struct PyMPICartcommObject;
struct PyMPIGraphcommObject;
struct PyMPIDistgraphcommObject;
struct PyMPIIntercommObject;
struct PyMPIWinObject;
struct PyMPIFileObject;

/* "mpi4py/MPI.pxd":28
 *     ctypedef MPI_Count  Count  "MPI_Count"
 * 
 * ctypedef public api class Datatype [             # <<<<<<<<<<<<<<
 *     type   PyMPIDatatype_Type,
 *     object PyMPIDatatypeObject,
 */
struct PyMPIDatatypeObject {
  PyObject_HEAD
  MPI_Datatype ob_mpi;
  unsigned int flags;
  PyObject *__weakref__;
};
typedef struct PyMPIDatatypeObject PyMPIDatatypeObject;

/* "mpi4py/MPI.pxd":36
 *     cdef object     __weakref__
 * 
 * ctypedef public api class Status [             # <<<<<<<<<<<<<<
 *     type   PyMPIStatus_Type,
 *     object PyMPIStatusObject,
 */
struct PyMPIStatusObject {
  PyObject_HEAD
  MPI_Status ob_mpi;
  unsigned int flags;
  PyObject *__weakref__;
};
typedef struct PyMPIStatusObject PyMPIStatusObject;

/* "mpi4py/MPI.pxd":44
 *     cdef object   __weakref__
 * 
 * ctypedef public api class Request [             # <<<<<<<<<<<<<<
 *     type   PyMPIRequest_Type,
 *     object PyMPIRequestObject,
 */
struct PyMPIRequestObject {
  PyObject_HEAD
  MPI_Request ob_mpi;
  unsigned int flags;
  PyObject *__weakref__;
  PyObject *ob_buf;
};
typedef struct PyMPIRequestObject PyMPIRequestObject;

/* "mpi4py/MPI.pxd":53
 *     cdef object      ob_buf
 * 
 * ctypedef public api class Prequest(Request) [             # <<<<<<<<<<<<<<
 *     type   PyMPIPrequest_Type,
 *     object PyMPIPrequestObject,
 */
struct PyMPIPrequestObject {
  struct PyMPIRequestObject __pyx_base;
};
typedef struct PyMPIPrequestObject PyMPIPrequestObject;

/* "mpi4py/MPI.pxd":59
 *     pass
 * 
 * ctypedef public api class Grequest(Request) [             # <<<<<<<<<<<<<<
 *     type   PyMPIGrequest_Type,
 *     object PyMPIGrequestObject,
 */
struct PyMPIGrequestObject {
  struct PyMPIRequestObject __pyx_base;
  MPI_Request ob_grequest;
};
typedef struct PyMPIGrequestObject PyMPIGrequestObject;

/* "mpi4py/MPI.pxd":65
 *     cdef MPI_Request ob_grequest
 * 
 * ctypedef public api class Message [             # <<<<<<<<<<<<<<
 *     type   PyMPIMessage_Type,
 *     object PyMPIMessageObject,
 */
struct PyMPIMessageObject {
  PyObject_HEAD
  MPI_Message ob_mpi;
  unsigned int flags;
  PyObject *__weakref__;
  PyObject *ob_buf;
};
typedef struct PyMPIMessageObject PyMPIMessageObject;

/* "mpi4py/MPI.pxd":74
 *     cdef object      ob_buf
 * 
 * ctypedef public api class Op [             # <<<<<<<<<<<<<<
 *     type   PyMPIOp_Type,
 *     object PyMPIOpObject,
 */
struct PyMPIOpObject {
  PyObject_HEAD
  MPI_Op ob_mpi;
  unsigned int flags;
  PyObject *__weakref__;
  PyObject *(*ob_func)(PyObject *, PyObject *);
  int ob_usrid;
};
typedef struct PyMPIOpObject PyMPIOpObject;

/* "mpi4py/MPI.pxd":84
 *     cdef int      ob_usrid
 * 
 * ctypedef public api class Group [             # <<<<<<<<<<<<<<
 *     type   PyMPIGroup_Type,
 *     object PyMPIGroupObject,
 */
struct PyMPIGroupObject {
  PyObject_HEAD
  MPI_Group ob_mpi;
  unsigned int flags;
  PyObject *__weakref__;
};
typedef struct PyMPIGroupObject PyMPIGroupObject;

/* "mpi4py/MPI.pxd":92
 *     cdef object  __weakref__
 * 
 * ctypedef public api class Info [             # <<<<<<<<<<<<<<
 *     type   PyMPIInfo_Type,
 *     object PyMPIInfoObject,
 */
struct PyMPIInfoObject {
  PyObject_HEAD
  MPI_Info ob_mpi;
  unsigned int flags;
  PyObject *__weakref__;
};
typedef struct PyMPIInfoObject PyMPIInfoObject;

/* "mpi4py/MPI.pxd":100
 *     cdef object __weakref__
 * 
 * ctypedef public api class Errhandler [             # <<<<<<<<<<<<<<
 *     type   PyMPIErrhandler_Type,
 *     object PyMPIErrhandlerObject,
 */
struct PyMPIErrhandlerObject {
  PyObject_HEAD
  MPI_Errhandler ob_mpi;
  unsigned int flags;
  PyObject *__weakref__;
};
typedef struct PyMPIErrhandlerObject PyMPIErrhandlerObject;

/* "mpi4py/MPI.pxd":108
 *     cdef object       __weakref__
 * 
 * ctypedef public api class Comm [             # <<<<<<<<<<<<<<
 *     type   PyMPIComm_Type,
 *     object PyMPICommObject,
 */
struct PyMPICommObject {
  PyObject_HEAD
  MPI_Comm ob_mpi;
  unsigned int flags;
  PyObject *__weakref__;
};
typedef struct PyMPICommObject PyMPICommObject;

/* "mpi4py/MPI.pxd":116
 *     cdef object __weakref__
 * 
 * ctypedef public api class Intracomm(Comm) [             # <<<<<<<<<<<<<<
 *     type   PyMPIIntracomm_Type,
 *     object PyMPIIntracommObject,
 */
struct PyMPIIntracommObject {
  struct PyMPICommObject __pyx_base;
};
typedef struct PyMPIIntracommObject PyMPIIntracommObject;

/* "mpi4py/MPI.pxd":122
 *     pass
 * 
 * ctypedef public api class Topocomm(Intracomm) [             # <<<<<<<<<<<<<<
 *     type   PyMPITopocomm_Type,
 *     object PyMPITopocommObject,
 */
struct PyMPITopocommObject {
  struct PyMPIIntracommObject __pyx_base;
};
typedef struct PyMPITopocommObject PyMPITopocommObject;

/* "mpi4py/MPI.pxd":128
 *     pass
 * 
 * ctypedef public api class Cartcomm(Topocomm) [             # <<<<<<<<<<<<<<
 *     type   PyMPICartcomm_Type,
 *     object PyMPICartcommObject,
 */
struct PyMPICartcommObject {
  struct PyMPITopocommObject __pyx_base;
};
typedef struct PyMPICartcommObject PyMPICartcommObject;

/* "mpi4py/MPI.pxd":134
 *     pass
 * 
 * ctypedef public api class Graphcomm(Topocomm) [             # <<<<<<<<<<<<<<
 *     type   PyMPIGraphcomm_Type,
 *     object PyMPIGraphcommObject,
 */
struct PyMPIGraphcommObject {
  struct PyMPITopocommObject __pyx_base;
};
typedef struct PyMPIGraphcommObject PyMPIGraphcommObject;

/* "mpi4py/MPI.pxd":140
 *     pass
 * 
 * ctypedef public api class Distgraphcomm(Topocomm) [             # <<<<<<<<<<<<<<
 *     type   PyMPIDistgraphcomm_Type,
 *     object PyMPIDistgraphcommObject,
 */
struct PyMPIDistgraphcommObject {
  struct PyMPITopocommObject __pyx_base;
};
typedef struct PyMPIDistgraphcommObject PyMPIDistgraphcommObject;

/* "mpi4py/MPI.pxd":146
 *     pass
 * 
 * ctypedef public api class Intercomm(Comm) [             # <<<<<<<<<<<<<<
 *     type   PyMPIIntercomm_Type,
 *     object PyMPIIntercommObject,
 */
struct PyMPIIntercommObject {
  struct PyMPICommObject __pyx_base;
};
typedef struct PyMPIIntercommObject PyMPIIntercommObject;

/* "mpi4py/MPI.pxd":152
 *     pass
 * 
 * ctypedef public api class Win [             # <<<<<<<<<<<<<<
 *     type   PyMPIWin_Type,
 *     object PyMPIWinObject,
 */
struct PyMPIWinObject {
  PyObject_HEAD
  MPI_Win ob_mpi;
  unsigned int flags;
  PyObject *__weakref__;
  PyObject *ob_mem;
};
typedef struct PyMPIWinObject PyMPIWinObject;

/* "mpi4py/MPI.pxd":161
 *     cdef object   ob_mem
 * 
 * ctypedef public api class File [             # <<<<<<<<<<<<<<
 *     type   PyMPIFile_Type,
 *     object PyMPIFileObject,
 */
struct PyMPIFileObject {
  PyObject_HEAD
  MPI_File ob_mpi;
  unsigned int flags;
  PyObject *__weakref__;
};
typedef struct PyMPIFileObject PyMPIFileObject;

#ifndef __PYX_HAVE_API__mpi4py__MPI

#ifndef __PYX_EXTERN_C
  #ifdef __cplusplus
    #define __PYX_EXTERN_C extern "C"
  #else
    #define __PYX_EXTERN_C extern
  #endif
#endif

#ifndef DL_IMPORT
  #define DL_IMPORT(_T) _T
#endif

__PYX_EXTERN_C DL_IMPORT(PyTypeObject) PyMPIDatatype_Type;
__PYX_EXTERN_C DL_IMPORT(PyTypeObject) PyMPIStatus_Type;
__PYX_EXTERN_C DL_IMPORT(PyTypeObject) PyMPIRequest_Type;
__PYX_EXTERN_C DL_IMPORT(PyTypeObject) PyMPIPrequest_Type;
__PYX_EXTERN_C DL_IMPORT(PyTypeObject) PyMPIGrequest_Type;
__PYX_EXTERN_C DL_IMPORT(PyTypeObject) PyMPIMessage_Type;
__PYX_EXTERN_C DL_IMPORT(PyTypeObject) PyMPIOp_Type;
__PYX_EXTERN_C DL_IMPORT(PyTypeObject) PyMPIGroup_Type;
__PYX_EXTERN_C DL_IMPORT(PyTypeObject) PyMPIInfo_Type;
__PYX_EXTERN_C DL_IMPORT(PyTypeObject) PyMPIErrhandler_Type;
__PYX_EXTERN_C DL_IMPORT(PyTypeObject) PyMPIComm_Type;
__PYX_EXTERN_C DL_IMPORT(PyTypeObject) PyMPIIntracomm_Type;
__PYX_EXTERN_C DL_IMPORT(PyTypeObject) PyMPITopocomm_Type;
__PYX_EXTERN_C DL_IMPORT(PyTypeObject) PyMPICartcomm_Type;
__PYX_EXTERN_C DL_IMPORT(PyTypeObject) PyMPIGraphcomm_Type;
__PYX_EXTERN_C DL_IMPORT(PyTypeObject) PyMPIDistgraphcomm_Type;
__PYX_EXTERN_C DL_IMPORT(PyTypeObject) PyMPIIntercomm_Type;
__PYX_EXTERN_C DL_IMPORT(PyTypeObject) PyMPIWin_Type;
__PYX_EXTERN_C DL_IMPORT(PyTypeObject) PyMPIFile_Type;

#endif /* !__PYX_HAVE_API__mpi4py__MPI */

/* WARNING: the interface of the module init function changed in CPython 3.5. */
/* It now returns a PyModuleDef instance instead of a PyModule instance. */

#if PY_MAJOR_VERSION < 3
PyMODINIT_FUNC initMPI(void);
#else
PyMODINIT_FUNC PyInit_MPI(void);
#endif

#endif /* !__PYX_HAVE__mpi4py__MPI */
