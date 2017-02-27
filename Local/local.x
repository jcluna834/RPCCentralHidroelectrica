struct proclocal_sx{
	int idProceso;	
	string nomUsuario<35>;
	string direccion<30>;
	float lectura;
};
typedef struct proclocal_sx proclocal_sx;

struct idEsclavos_sx{
	int idProcEsclavos[5];
};
typedef struct idEsclavos_sx idEsclavos_sx;

program LOCAL_SX{
	version LOCAL_SX_VERSION{	
		int getIdLocal() = 1;
		idEsclavos_sx getId_esclavos() = 2;
		int getIdSlove(int id) = 3;
		string getNomSlove(int id) = 4;
		string getDirSlove(int id) = 5;
		float getLecSlove(int id) = 6;


	} = 1;
}	= 0x3C000002; 
