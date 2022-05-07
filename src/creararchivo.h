void llenar_archivo(){
	
	precisiontxt = fopen("./src/propiedades.txt","w");
	

	fprintf(precisiontxt,"Disco %i:\n",nbi);
	//fwrite(str , 1 , sizeof(str) , fp );
	fprintf(precisiontxt,"Media real: \n");
	fprintf(precisiontxt,"Media imaginaria: \n");
	fprintf(precisiontxt,"Potencia: \n");
	fprintf(precisiontxt,"Ruido total: \n");	
	

	fclose(precisiontxt);
}
