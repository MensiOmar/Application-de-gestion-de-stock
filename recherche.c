//fonction recherche 
int research (int idrech )
{
	file *F;
	F = fopen("stock.txt","r");
	do
	{
		fscanf(F,"%d ;%d ;%s ;%d ;%d ;%d ;%d ;%d ;%d ;%d|n",&produit.pa,&produit.pv,&produit.nom,&produit.delai.jour,&produit.delai.mois,&produit.delai.annee,&produit.quant,&produit.fragilite,&produit.id,&produit.importance);
		fflush(stdin);
		if (produit.id=idrech)
		{
			fclose(F);
			return 1;
		}
	}while(!feof(F));

fclose(F);
return -1;
}
//recherche et affichage 
void recherche()
{
	int idrech;
	printf("entrer le numero de serie de produit shouaite de le rechercher|n");
	scanf("%d",&idrech);
	file *F;
	F = fopen("stock.txt","r");
	do
	{
		fscanf(F,"%d ;%d ;%s ;%d ;%d ;%d ;%d ;%d ;%d ;%d|n",&produit.pa,&produit.pv,&produit.nom,&produit.delai.jour,&produit.delai.mois,&produit.delai.annee,&produit.quant,&produit.fragilite,&produit.id,&produit.importance);
		fflush(stdin);
		if (idrech==produit.id)
		{
			print_produit();
		}
	}while(!feof(F));

fclose(F);

}
