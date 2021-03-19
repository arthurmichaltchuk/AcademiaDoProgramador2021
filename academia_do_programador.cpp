#include <string>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

void menuedicao();
void edicao();
void exclusao();
void chamada();
void menuchamadoedicao();
void chamadoedicao();
void chamadoexclusao();
void tempochamado();
void data();

//1 Controle de Equipamentos

	vector<string> nomes;	//nome do produto min 6 caracteres
	vector<string> valores;	//preço do produto USE . 
	vector<string> numeros;	//numero de serie
	vector<string> datas;	//data de fabricação
	vector<string> fabris;	//fabricante
	
//2 Controle de Chamados

	vector<string> titulos;
	vector<string> descris;
	vector<string> equips;
	vector<int> aberts;
	vector<int> confirma;
	int datatual[0];

main ()
{setlocale (LC_ALL, "Portuguese");

	int choice;
	int choice2;
	int choice3;	
	int i;
	
	string nome;
	string valor;	
	string numero;
	string data;
	string fabri;
	char min[50];

	do
	{
		cout<<"\n                      Menu principal"<<endl;
		cout<<"__________________________________________________________\n"<<endl;
		cout<<"1. Registrar equipamentos"<<endl<<"2. Mostrar inventário"<<endl<<"3. Gerenciar inventário"<<endl<<"4. Chamados de manutenções"<<endl<<"5. Sair"<<endl<<"__________________________________________________________"<<endl;;	
		cin>>choice;	
		
				
		switch(choice)
		{
	
			case 1:			//	Registrar equipamentos
				system("cls");	
				cout<<"    Use '_' como espaço e '.' no campo do valor para evitar problemas. \n"<<endl;
				cout<<"1- Nome do equipamento: "<<endl;
				cin>>min;				
				if(strlen(min)<6){
				system("cls");
				cout<<"Precisa ter no mínimo 6 caracteres\n";
				choice = 1;
				system("pause");
				system("cls");
				break;
				}
				else
				{
				cout<<("1- Confirme o nome: \n");
				cin>>nome;
				nomes.push_back(nome);					
				}

				cout<<"2- Preço do equipamento: \n";
				cin>>valor;
				valores.push_back(valor);
			
				cout<<"3- Número de série: \n";
				cin>>numero;
				numeros.push_back(numero);
		
				cout<<"4- Data de fabricação: \n";
				cin>>data;
				datas.push_back(data);				
				
				cout<<"5- Fabricante: \n";
				cin>>fabri;
				fabris.push_back(fabri);
											
				system("pause");
				system("cls");
				cout<<("    Registrado com sucesso!\n");
				system("pause");
				system("cls");						
				break;
			case 2:		//Mostrar inventário
				if (!numeros.empty()){
									
					system("cls");	
					cout<<"Inventário: "<<endl<<endl;
					for (int i = 0; i < numeros.size(); i++)
					{
						if(numeros[i].empty()){			//verica se o item nao foi excluído			
							cout<<"    Item "<<i<<" excluido."<<endl<<endl<<endl;
						}
						else		
						{
							cout<<"Item número: "<<i<<endl<<endl;
							cout<<"1- Nome do equipamento: "<< nomes[i]<<endl;
							cout<<"2- Preço do equipamento: "<< valores[i]<<endl;				
							cout<<"3- Número de série: "<< numeros[i]<<endl;				
							cout<<"4- Data de fabricação: "<< datas[i]<<endl;
							cout<<"5- Fabricante: "<< fabris[i]<<endl<<endl;																					
						}							
					}	
					system("pause");
					system("cls");															
				}
				else
				{
				system("cls");
				cout<<"Nenhum item no inventário: "<<endl;	
				system("pause");				
				}
				system("cls");				
				break;
			case 3:			//Gerenciar inventário
				system("cls");
				menuedicao();
				break;	
			case 4:			//Chamados de manutenções
				system("cls");
				chamada();
				break;
			case 5:			//Sair
				system("cls");				
				cout<<"Fechando...\n";
				return 0;
				system("pause");											
			default:
				cout<<"input errado"<<endl;
				system("pause");
				system("cls");	
				break;				
		}	
	}
	while(choice != 5);	
	return 0;		
}	
	
void menuedicao(){
	int choice2;
	int item1;
	int item2;
			
		do
		{	
		
			cout<<"\n                      Menu de edição"<<endl;
			cout<<"__________________________________________________________\n";
			cout<<endl<<"1. Escolher item para editar"<<endl<<"2. Excluir item"<<endl<<"3. Voltar"<<endl<<"__________________________________________________________\n"<<endl;	
			cin>>choice2;				
		
			switch(choice2){								
				case 1:			//escolher item para editar
					system("cls");
					edicao();
					system("cls");
					break;						
				case 2:			//Excluir item
					exclusao();
					system("cls");
					break;
				case 3:			//Voltar
					cout<<"Voltar ao menu";
					system("cls");
											
				break;		
						
			}
		}
		while(choice2 != 3);
}

void edicao(){
	char min[50];
	int i, item, ii;
		
	if (!numeros.empty()){			//para detectar se tem algum item no inventario, se nao tive volta ao menu 
									
		system("cls");	
		cout<<"Equipamentos resgistrados no inventário: "<<endl<<endl;
		for (int i = 0; i < numeros.size(); i++)
		{				
			if(numeros[i].empty()){		//verica se o item nao foi excluído					
				cout<<"    Item "<<i<<" excluido."<<endl<<endl<<endl;
			}
			else		//mostrar todo inventario para ajudar na escolha
			{
				cout<<"Número do item: "<<i<<endl<<endl;
				cout<<"1- Nome do equipamento: "<< nomes[i]<<endl;
				cout<<"2- Preço do equipamento: "<< valores[i]<<endl;				
				cout<<"3- Número de série: "<< numeros[i]<<endl;				
				cout<<"4- Data de fabricação: "<< datas[i]<<endl;
				cout<<"5- Fabricante: "<< fabris[i]<<endl<<endl;																					
			}							
		}

		cout<<"Digite o número do item no inventário que deseja editar: "<<endl;
		cin>>ii;

		
		cout<<"Digite o que quer editar no item: "<<endl;
		cout<<"1. Nome"<<endl<<"2. Preço"<<endl<<"3. Número de série"<<endl<<"4. Data de fabricação"<<endl<<"5. Fabricante"<<endl;
		cin>>item;
		cout<<"\n    Use '_' como espaço e '.' no campo do valor para evitar problemas. \n"<<endl;
		switch(item){
		
			case 1:					//escolha do que quer editar
	
				cout<<"Digite o novo nome: "<<endl;
				cin>>min;				
				if(strlen(min)<6){		//limita em no minimo 6 caracteres no nome
				system("cls");
				cout<<"Precisa ter no mínimo 6 caracteres\n";
				item = 0;
				system("pause");
				system("cls");
				break;
				}
				else
				{
				cout<<("1- Confirme o novo nome: \n");
				cin>>nomes[ii];
				system("cls");				
				}
				break;
																	
			case 2:
				cout<<"Digite o novo preço do equipamento: "<<endl;
				cin>>valores[ii];	
				system("cls");	
				break;								
			case 3:	
				cout<<"Digite o novo número de série: "<<endl;
				cin>>numeros[ii];	
				system("cls");	
				break;								
			case 4:
				cout<<"Digite a nova data de fabricação: "<<endl;
				cin>>datas[ii];	
				system("cls");
				break;						
			case 5:
				cout<<"Digite a nova fabricante: "<<endl;
				cin>>fabris[ii];	
				system("cls");				
			break;
		}
	}
	else
	{
		cout<<"Nenhum item para editar"<<endl;
		system("pause");
		system("cls");	
	}
	

}

void exclusao(){
	
	int i, item, ii;
	
	if (!numeros.empty()){		//nao deixa excluir se o inventario estiver vazio
									
		system("cls");	

		cout<<"\n          Equipamentos resgistrados no inventário: "<<endl;
		cout<<"__________________________________________________________\n"<<endl;		
		cout<<""<<endl<<endl;
		for (int i = 0; i < numeros.size(); i++)
		{				
			if(numeros[i].empty()){		//verica se o item nao foi excluído					
				cout<<"    Item "<<i<<" excluido."<<endl<<endl<<endl;
			}
			else		//mostrar todo inventario para ajudar na escolha
			{		
				cout<<"Número do item: "<<i<<endl<<endl;
				cout<<"1- Nome do equipamento: "<< nomes[i]<<endl;
				cout<<"2- Preço do equipamento: "<< valores[i]<<endl;				
				cout<<"3- Número de série: "<< numeros[i]<<endl;				
				cout<<"4- Data de fabricação: "<< datas[i]<<endl;
				cout<<"5- Fabricante: "<< fabris[i]<<endl<<endl<<endl;																					
			}							
		}	
		
		cout<<"Digite o número do item no inventário que deseja excluir: "<<endl;
		cin>>ii;

		numeros[ii].clear();		//limpa o vetor 
																	
	}	
	else
	{
		system("cls");		
		cout<<"\nNenhum item para excluir"<<endl;
		system("pause");
		system("cls");	
	}
}

void chamada(){
	
	int choice;	
	string titulo;
	string descri;
	string equip;	
	string abert;
	int i;	
		
	do			//segundo menu principal
		{			
			cout<<"\n                      Menu de chamados"<<endl;
			cout<<"__________________________________________________________\n"<<endl;	
			cout<<"1. Registrar chamado"<<endl<<"2. Visualizar chamados"<<endl<<"3. Gerenciar Chamados"<<endl<<"4. Alterar data"<<endl<<"5. Voltar"<<endl<<"__________________________________________________________\n"<<endl;;	
			cin>>choice;	
		
			switch(choice)
			{
		
				case 1:		//Registrar chamado
					system("cls");
					cout<<"    Use '_' como espaço e '.' no campo do valor para evitar problemas."<<endl<<endl;
					cout<<"Título do chamado: \n";
					cin>>titulo;
					titulos.push_back(titulo);	

					cout<<"Descrição do chamado: \n";	//USAR "_" COMO ESPAÇO
					cin>>descri;
					descris.push_back(descri);
				
					cout<<"Equipamento: \n";
					cin>>equip;
					equips.push_back(equip);
					
					tempochamado();
										
					system("cls");
					break;
				case 2:			//Visualizar chamados
					if (!titulos.empty()){				
				
						system("cls");	
						cout<<"\n          Equipamentos resgistrados no inventário: "<<endl;
						cout<<"__________________________________________________________\n"<<endl;				
						for (int i = 0; i < titulos.size(); i++)
						{
							if(titulos[i].empty()){						
							cout<<"    Chamado "<<i<<" excluido."<<endl<<endl<<endl;
							}
							else
							{
							cout<<"   Número do chamado: "<<i<<endl<<endl;
							cout<<"1- Título do chamado: "<< titulos[i]<<endl;
							cout<<"2- Descrição do chamado: "<< descris[i]<<endl;				
							cout<<"3- Equipamento: "<< equips[i]<<endl;				
							cout<<"4- Dias em aberto: "<< datatual[0]-aberts[i]<<endl<<endl;																					
							}	
						}
						system("pause");
						system("cls");																				
					}
					else
					{
					system("cls");
					cout<<"Nenhuma chamada. "<<endl;	
					system("pause");				
					}
					system("cls");				
					break;
				case 3:			//Gerenciar Chamados
					system("cls");
					menuchamadoedicao();
					break;	
				case 4:			//Alterar data
					data();
				case 5:			//Voltar
					system("cls");
					break;							
				default:
					cout<<"input errado"<<endl;
					system("pause");
					system("cls");	
					break;				
			}
		
	}	while(choice != 5);
}

void data(){
	
	int diaa,mesa,anoa,somas;
		//menu para editar data
		system("cls");			
		cout<<"\n                      Alterar data"<<endl;
		cout<<"__________________________________________________________\n"<<endl;
		cout<<"Digite o dia atual: \n";
		cin>>diaa;
		cout<<"Digite o mes atual: \n";
		cin>>mesa;
		cout<<"Digite o ano atual: \n";
		cin>>anoa;		
		
		somas = (anoa*365)+(mesa*12)+diaa;		//converti tudo em dias
		datatual[0] = somas;					//vetor com um unico espaço que foi o que funcionou perfeitamente para data atual
		cout<<"Data atual alterada! \n"<<endl;
		confirma.push_back(somas); 				//confirma se ja ouve alteraçao na data atual ou se precisa criar pela primeira vez
}

void menuchamadoedicao(){
	int choice2;
	int item1;
	int item2;
		
		do			//sub menu de edicao do chamado
		{		
			cout<<"\n                      Menu edição de chamados"<<endl;
			cout<<"__________________________________________________________\n";	
			cout<<endl<<"1. Escolher chamado para editar"<<endl<<"2. Excluir chamado"<<endl<<"3. Voltar"<<endl<<"__________________________________________________________\n"<<endl;
			cin>>choice2;				
		
			switch(choice2){
									
				case 1:				//Escolher chamado para editar
					chamadoedicao();
					system("cls");
					break;						
				case 2:				//Excluir chamado
					chamadoexclusao();
					system("cls");
					break;
				case 3:				//Voltar
					cout<<"Voltar ao menu";
					system("cls");
											
				break;		
						
			}
		}
		while(choice2 != 3);
	
}

void chamadoedicao(){
	
	int i, item, ii;
	int diaa,mesa,anoa,somas;	
	
	if (!titulos.empty()){

		system("cls");	

		cout<<"\n          Equipamentos resgistrados no inventário: "<<endl;
		cout<<"__________________________________________________________\n"<<endl;				
		for (int i = 0; i < titulos.size(); i++)
		{
			if(titulos[i].empty()){						
				cout<<"      Chamado "<<i<<" excluido."<<endl<<endl<<endl;
			}
			else		//mostrar todo inventario para ajudar na escolha
			{
				cout<<"   Número do chamado: "<<i<<endl<<endl;
				cout<<"1- Título do chamado: "<< titulos[i]<<endl;
				cout<<"2- Descrição do chamado: "<< descris[i]<<endl;				
				cout<<"3- Equipamento: "<< equips[i]<<endl;				
				cout<<"4- Data de abertura: "<<datatual[0]-aberts[i]<<endl<<endl;																					
			}	
		}
		
		cout<<"\n     Digite o número do item no inventário que deseja editar: "<<endl;
		cin>>ii;

		
		cout<<"\n     Digite o que quer editar no item: "<<endl;
		cout<<"\n1. Título do chamado "<<endl<<"2. Descrição do chamado "<<endl<<"3. Equipamento"<<endl<<"4. Data de abertura"<<endl;
		cin>>item;
		cout<<"    Use '_' como espaço e '.' no campo do valor para evitar problemas. \n"<<endl;
		switch(item){
		
			case 1:					
				cout<<"\nDigite o novo título do chamado: "<<endl;
				cin>>titulos[ii];		
				system("cls");
				break;									
			case 2:
				cout<<"\nDigite a nova descrição do chamado: "<<endl;
				cin>>descris[ii];	
				system("cls");	
				break;								
			case 3:	
				cout<<"\nDigite o novo equipamento: "<<endl;
				cin>>equips[ii];	
				system("cls");	
				break;								
			case 4:		
				cout<<"Digite o novo dia do chamado: \n";
				cin>>diaa;
				cout<<"Digite o novo mes do chamado: \n";
				cin>>mesa;
				cout<<"Digite o novo ano do chamado: \n";
				cin>>anoa;

				somas = (anoa*365)+(mesa*12)+diaa;		//converção tudo para dias
				cout<<"Total de dias de chamado: "<<somas<<endl<<endl<<"Confirme o total de dias: \n";
				cin>>aberts[ii]; 		//alteração do vetor que define o dia da chamada
				system("cls");						
			break;
		}
	}
	else
	{
		cout<<"\n    Nenhum chamado para editar"<<endl;
		system("pause");
		system("cls");	
	}
		
}

void chamadoexclusao(){
	
	
	int i, item, ii;
	
	if (!titulos.empty()){
									
		system("cls");	

		cout<<"\n          Equipamentos resgistrados no inventário: "<<endl;
		cout<<"__________________________________________________________\n"<<endl;		
		for (int i = 0; i < titulos.size(); i++)
		{				
			if(titulos[i].empty()){						
				cout<<"    Chamado "<<i<<" excluido."<<endl<<endl<<endl;
			}
			else		//mostrar todo inventario para ajudar na escolha
			{
				cout<<"   Número do chamado: "<<i<<endl<<endl;
				cout<<"1- Título do chamado: "<< titulos[i]<<endl;
				cout<<"2- Descrição do chamado: "<< descris[i]<<endl;				
				cout<<"3- Equipamento: "<< equips[i]<<endl;				
				cout<<"4- Data de abertura: "<<datatual[0]-aberts[i]<<endl<<endl;																					
			}							
		}	
		
		cout<<"   Digite o número do chamado no inventário que deseja excluir: "<<endl;
		cin>>ii;

		titulos[ii].clear(); 		//limpa o vetor 
															
	}	
	else
	{
		cout<<"\n  Nenhum chamado para excluir"<<endl;
		system("pause");
		system("cls");	
	}
}

void tempochamado(){	
	
	int total,somas,somaa;
	int dian,mesn,anon,diaa,mesa,anoa;	
	int dias,mess,anos,soma;
	
	cout<<"Digite o dia da abertura do chamado: \n";
	cin>>diaa;
	cout<<"Digite o mes da abertura do chamado: \n";
	cin>>mesa;
	cout<<"Digite o ano da abertura do chamado: \n";
	cin>>anoa;	
	

	if(confirma.empty())		//verifica se existe dia atual
	{
		cout<<"Data atual definida para o dia do chamado! \n"<<endl;	
		
		somas = (anoa*365)+(mesa*12)+diaa;
		datatual[0] = somas;	
	
		total = (anoa*365)+(mesa*12)+diaa;
		aberts.push_back(somas);		//vetor dos dias em aberto
		confirma.push_back(total); 		//vetor de verificação do dia atual
		system("pause");
	}
	else
	{
		soma = (anoa*365)+(mesa*30)+diaa;	
		aberts.push_back(soma);		
	}	
}
