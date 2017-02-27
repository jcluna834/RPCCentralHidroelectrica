/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _LOCAL_H_RPCGEN
#define _LOCAL_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif
#define TAM 5

struct proclocal_sx {
	int idProceso;
	char *nomUsuario;
	char *direccion;
	float lectura;
};
typedef struct proclocal_sx proclocal_sx;

CLIENT *esclavos[TAM];
int dirLocal;

struct idEsclavos_sx {
	int idProcEsclavos[5];
};
typedef struct idEsclavos_sx idEsclavos_sx;
idEsclavos_sx idProc;


#define LOCAL_SX 0x3C000002
#define LOCAL_SX_VERSION 1

#if defined(__STDC__) || defined(__cplusplus)
#define getIdLocal 1
extern  int * getidlocal_1(void *, CLIENT *);
extern  int * getidlocal_1_svc(void *, struct svc_req *);
#define getId_esclavos 2
extern  idEsclavos_sx * getid_esclavos_1(void *, CLIENT *);
extern  idEsclavos_sx * getid_esclavos_1_svc(void *, struct svc_req *);
#define getIdSlove 3
extern  int * getidslove_1(int *, CLIENT *);
extern  int * getidslove_1_svc(int *, struct svc_req *);
#define getNomSlove 4
extern  char ** getnomslove_1(int *, CLIENT *);
extern  char ** getnomslove_1_svc(int *, struct svc_req *);
#define getDirSlove 5
extern  char ** getdirslove_1(int *, CLIENT *);
extern  char ** getdirslove_1_svc(int *, struct svc_req *);
#define getLecSlove 6
extern  float * getlecslove_1(int *, CLIENT *);
extern  float * getlecslove_1_svc(int *, struct svc_req *);
extern int local_sx_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define getIdLocal 1
extern  int * getidlocal_1();
extern  int * getidlocal_1_svc();
#define getId_esclavos 2
extern  idEsclavos_sx * getid_esclavos_1();
extern  idEsclavos_sx * getid_esclavos_1_svc();
#define getIdSlove 3
extern  int * getidslove_1();
extern  int * getidslove_1_svc();
#define getNomSlove 4
extern  char ** getnomslove_1();
extern  char ** getnomslove_1_svc();
#define getDirSlove 5
extern  char ** getdirslove_1();
extern  char ** getdirslove_1_svc();
#define getLecSlove 6
extern  float * getlecslove_1();
extern  float * getlecslove_1_svc();
extern int local_sx_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_proclocal_sx (XDR *, proclocal_sx*);
extern  bool_t xdr_proclocal_sx (XDR *, proclocal_sx*);
extern  bool_t xdr_idEsclavos_sx (XDR *, idEsclavos_sx*);
extern  bool_t xdr_idEsclavos_sx (XDR *, idEsclavos_sx*);

#else /* K&R C */
extern bool_t xdr_proclocal_sx ();
extern bool_t xdr_proclocal_sx ();
extern bool_t xdr_idEsclavos_sx ();
extern bool_t xdr_idEsclavos_sx ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_LOCAL_H_RPCGEN */
