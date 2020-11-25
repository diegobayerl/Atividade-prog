#include <stdio.h>

struct Produto{
    float preco;
    char nome[40], categoria[40];
    int quantidade;
    float valorTotalProduto;
};


int quantidadeProduto = 0; //contador global
int quantidadeVetor = 10; // quantidade vetor
float ValorTotal = 0; // valor + quantidade de todos os produtos 
float Desconto = 0; // Desconto do Produto

void inserir(struct Produto NewProduto[quantidadeVetor]){
    
    ValorTotal = 0; // setar variável caso faça um produto por vez!
    
    printf("Qual o nome do produto ? \n");
    scanf("%[^\n]s", NewProduto[quantidadeProduto].nome);
    
    printf("\e[H\e[2J");
    
    printf ("incluir produto\n");
    setbuf(stdin,NULL);
    
    
    
    printf("Qual a categoria do produto ? \n");
    scanf("%[^\n]s", NewProduto[quantidadeProduto].categoria);
    
    printf("\e[H\e[2J");
    printf ("incluir produto\n");
    setbuf(stdin,NULL);
    
   
    
    printf("Qual o preço do produto ? \n");
    scanf("%f", &NewProduto[quantidadeProduto].preco);
    
    printf("\e[H\e[2J");
    
    printf ("incluir produto\n");
    
    printf("Qual a quantidade do produto ? \n");
    scanf("%d", &NewProduto[quantidadeProduto].quantidade);
    
    printf("\e[H\e[2J");
    
    int opcaoinsert;
    do{
        printf("Produto adicionado com sucesso! \n");
        printf("1 - OK \n");
        printf("> ");
        scanf("%d", &opcaoinsert);
        setbuf(stdin,NULL);
    }while(opcaoinsert != 1);
    
    printf("\e[H\e[2J");
    printf("Escolha uma opção: \n");
    NewProduto[quantidadeProduto].valorTotalProduto = NewProduto[quantidadeProduto].quantidade * NewProduto[quantidadeProduto].preco;
    
    quantidadeProduto++;
}

void imprimir(struct Produto NewProduto[quantidadeVetor]){
    if(quantidadeProduto == 0){
        printf("Nenhum produto cadastrado \n");
    }
    else{
        for(int i=0; i < quantidadeProduto; i++){
            printf(">>>>>>>>>>>>>>>>>>>> Dados produto %d <<<<<<<<<<<<<<<<<<<<<<< \n", i+1);
            printf("O nome do produto %d é %s! \n", i+1, NewProduto[i].nome);
            printf("A categoria do produto %d é %s! \n", i+1, NewProduto[i].categoria);
            printf("O valor do produto %d é R$ %0.2f! \n", i+1, NewProduto[i].preco);
            printf("A quantidade do produto %d é %d unidade \n", i+1, NewProduto[i].quantidade);
            printf("O valor total do produto %d é R$ %0.2f! \n", i+1, NewProduto[i].valorTotalProduto);
            printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< \n");
        }
        
        int opcaoinsert;
                do{
                    printf("Voltar ao menu anterior ? \n");
                    printf("1 - OK \n");
                    printf("> ");
                    scanf("%d", &opcaoinsert);
                    printf("\e[H\e[2J");
                    setbuf(stdin,NULL);
                    
                     printf("Escolha uma opção: \n");
                }while(opcaoinsert != 1);
        
    }
       
}

void calcular(struct Produto NewProduto[quantidadeVetor]){
    
    ValorTotal = 0; // setar variável caso faça um produto por vez!
    int opcaoinsert;    
      
    if( quantidadeProduto == 0){
        printf("Não existe produtos para calcular preço");
        
                do{
                    printf("Voltar ao menu anterior ? \n");
                    printf("1 - OK \n");
                    printf("> ");
                    scanf("%d", &opcaoinsert);
                    printf("\e[H\e[2J");
                    setbuf(stdin,NULL);
                    
                     printf("Escolha uma opção: \n");
                }while(opcaoinsert != 1);
    }
    else{
        for(int i=0; i < quantidadeProduto; i++){
            ValorTotal += NewProduto[i].valorTotalProduto;
        }
        
        printf("Valor da compra é igual a R$ %0.2f \n", ValorTotal);
        
        if(ValorTotal > 100){
            Desconto = ValorTotal - (ValorTotal * 0.05);
            
            printf("O preço com desconto da o total de R$ %0.2f \n", Desconto);
        } 
        else{
            printf("O Produto não tem desconto! Obrigado \n");
        }
        
        do{
            printf("Voltar ao menu anterior ? \n");
            printf("1 - OK \n");
            printf("> ");
            scanf("%d", &opcaoinsert);
            printf("\e[H\e[2J");
            setbuf(stdin,NULL);
            printf("Escolha uma opção: \n");
        }while(opcaoinsert != 1);
        
    }
}

void menu(struct Produto NewProduto[quantidadeVetor]){
    int opcao;
    
    do{
        
        if(quantidadeVetor > quantidadeProduto){
            printf("Quantidade de produtos atual: %d e faltam %d \n", quantidadeProduto, quantidadeVetor - quantidadeProduto);
        }
        else{
            printf("Quantidade máxima atingida: %d \n", quantidadeProduto);
        }
        
        printf("1 - incluir um produto\n");
        printf("2 - mostrar produtos \n");
        printf("3 - Calcular compras\n");
        printf("0 - Sair\n");
        printf("> ");
        scanf("%d",&opcao);
        setbuf(stdin,NULL);
        
        printf("\e[H\e[2J");
        
        if(opcao==1){
            if(quantidadeVetor == quantidadeProduto){
                printf("Quantidade máxima atingida! \n");
                
                int opcaoinsert;
                do{
                    printf("1 - OK \n");
                    printf("> ");
                    scanf("%d", &opcaoinsert);
                    printf("\e[H\e[2J");
                    setbuf(stdin,NULL);
                }while(opcaoinsert != 1);
            }
            else{
                printf ("incluir produto\n");
                inserir(NewProduto);
            }
            
        }
        else if(opcao==2){
            printf("Listar produtos comprados:\n");
            imprimir(NewProduto);
            
        }
        else if(opcao==3){
            printf("Calcular preço dos produtos \n");
            calcular(NewProduto);
            
        }
        else if (opcao==0){
            printf("Obrigado por usar meu programa programa!");
        }
        else{
            printf("Opção inválida! Escolha outra opção: \n");
        }
    }while(opcao!= 0);
}  

int main(){
    printf("Quantos produtos quer cadastrar ? \n");
    printf("Como padrão, a quantidade é 10! \n");
    printf("> ");
    
    scanf("%d", &quantidadeVetor);
    
    printf("\e[H\e[2J");
    
    printf("Escolha uma opção: \n");
    struct Produto NewProduto[quantidadeVetor];
    menu(NewProduto);
}
