/***************************************************************************/
/* definicion de prototipos												   */
/***************************************************************************/

extern 	char	*pszEnviron 	( char *pszVarAmb
								, char *pszAmbiente);
extern 	char	*pszGetDateLog 	( void );
extern 	void	vFechaHora 		( void );
extern 	char 	*pszFechaHora 	( void );
extern 	int 	iMakeDir 		( char *pszDir);
extern 	long	lGetTimer 		( void );
extern 	char	*pszGetDate 	( void );
extern 	void	vWriteLog 		( FILE *Args, ...);



/******************************************************************************************/
/** Informaci�n de Versionado *************************************************************/
/******************************************************************************************/
/** Pieza                                               : */
/**  %ARCHIVE% */
/** Identificador en PVCS                               : */
/**  %PID% */
/** Producto                                            : */
/**  %PP% */
/** Revisi�n                                            : */
/**  %PR% */
/** Autor de la Revisi�n                                : */
/**  %AUTHOR% */
/** Estado de la Revisi�n ($TO_BE_DEFINED es Check-Out) : */
/**  %PS% */
/** Fecha de Creaci�n de la Revisi�n                    : */
/**  %DATE% */
/** Worksets ******************************************************************************/
/** %PIRW% */
/** Historia ******************************************************************************/
/** %PL% */
/******************************************************************************************/

