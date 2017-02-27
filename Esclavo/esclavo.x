struct procesclavos_sx{
	int idProceso;
	string nomUsuario<35>;
	string direccion<30>;
	float lectura;
};
typedef struct procesclavos_sx procesclavos_sx;

program ESCLAVO_SX{
	version ESCLAVO_SX_VERSION{
		int getIdEsclavo() = 1;
		string getNomEsclavo() = 2;
		string getDirEsclavo() = 3;
		float getLecEsclavo() = 4;
	
			
	} = 1;
}	= 0x3C000001;
