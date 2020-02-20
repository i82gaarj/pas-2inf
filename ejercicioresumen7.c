#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>



int main(int argc, char** argv){
    int c;

	static struct option long_options[] =
	{
		{"username",	 required_argument,	   0, 'u'},
		{"useruid",  required_argument,	   0, 'i'},
		{"groupname",  required_argument, 0, 'g'},
		{"allgroups",  no_argument, 0, 's'},
        {"allinfo",  no_argument, 0, 'a'},
		{"bactive",  no_argument, 0, 'b'},
        {"help",  no_argument, 0, 'h'},
		{0, 0, 0, 0}
	};

	/* Estas variables servirán para almacenar el resultado de procesar la línea de comandos */
	int hflag = 0;
	int bflag = 0;
    int aflag = 0;
    int sflag = 0;

	char *uvalue = NULL;
	char *ivalue = NULL;
	char *gvalue = NULL;

	/* getopt_long guardará el índice de la opción en esta variable. */
	int option_index = 0;
	
	opterr = 0;
	while ((c = getopt_long (argc, argv, "u:i:g:sabh", long_options, &option_index))!=-1)
	{
		/* El usuario ha terminado de introducir opciones */
		if (c == -1)
			break;
		switch (c)
		{
			case 'u':{
                aflag=1;
            }break;

			case 'i':
				bflag=1;
				break;

			case 'g':
				gvalue = optarg;
				break;

			case 's':
				sflag = 1;
				break;

			case 'a':
				fvalue = optarg;
				break;

            case 'b':
				//printf("Opción -f con valor '%s'\n", optarg);
				fvalue = optarg;
				break;

			case '?':
				/* getopt_long ya imprime su mensaje de error, no es necesario hacer nada */
				/* Si queremos imprimir nuestros propios errores, debemos poner opterr=0,
				 y hacer algo como lo que se expone a continuacion. Pruebe a hacer sus propios errores.
				if (optopt == 'c')
					fprintf (stderr, "La opción %c requiere un argumento.\n", optopt);*/
				break;

			default:
				abort ();
		}
		printf("optind: %d, optarg: %s, optopt: %c\n", optind, optarg, optopt);
	}

	/* Imprimir el resto de argumentos de la línea de comandos que no son opciones con "-" */
	if (optind < argc)
	{
		printf("Argumentos ARGV que no son opciones: ");
		while (optind < argc)
			printf("%s ", argv[optind++]);
		putchar ('\n');
	}
	printf ("aflag = %d, bflag = %d, cvalue = %s, dvalue = %s, fvalue = %s\n",aflag, bflag, cvalue, dvalue, fvalue);

	exit (0);



    
}