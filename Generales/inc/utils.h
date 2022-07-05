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
/** Información de Versionado *************************************************************/
/******************************************************************************************/
/** Pieza                                               : */
/**  %ARCHIVE% */
/** Identificador en PVCS                               : */
/**  %PID% */
/** Producto                                            : */
/**  %PP% */
/** Revisión                                            : */
/**  %PR% */
/** Autor de la Revisión                                : */
/**  %AUTHOR% */
/** Estado de la Revisión ($TO_BE_DEFINED es Check-Out) : */
/**  %PS% */
/** Fecha de Creación de la Revisión                    : */
/**  %DATE% */
/** Worksets ******************************************************************************/
/** %PIRW% */
/** Historia ******************************************************************************/
/** %PL% */
/******************************************************************************************/

