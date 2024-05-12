// implementação do k-means
// com k agrupamentos(clusters)
clear all;
clc;
// geração dos pontos
// distribuição gaussiana
x1=2+rand(1,10,'normal');  
y1=2+rand(1,10,'normal');  
x2=7+rand(1,10,'normal');  
y2=7+rand(1,10,'normal'); 
x3=2+rand(1,10,'normal'); 
y3=7+rand(1,10,'normal');  
x4=7+rand(1,10,'normal');  
y4=2+rand(1,10,'normal');  
x=[x1 x2 x3 x4];
y=[y1 y2 y3 y4];
pontos=[x' y'];
clf();
plot(x,y,'r*');
disp("Distribuição dos pontos");
//pause;
// inicialização dos parâmetros

k=4; // número de agrupamentos

// vetr b armazena agrupamento a que pertence o vetor de entrada
b=zeros(40,1);
bnovo=ones(40,1);

//// inicialização aleatória das centróides
//for centroide=1:numcentroides
//    for atributo=1:2
//        cluster(centroide,atributo)=11*rand(1,1,'uniform');
//    end
//    plot(cluster(centroide, atributo), 'g+');
//end

// inicialização com pontos da base de dados
for j=1:k
    cluster(j,:)=pontos(round(40*rand(1,1,'uniform')),:);
    plot(cluster(j,1),cluster(j,2), 'g+');
end
disp("distribuição das centróides");
//pause();
// ---- treinamento -----
// condição de parada: a) centróides não mudam de posição
//                     b) alcança número de iterações
iteracoesmax=4000
iteracao=0;
while ~isequal(b, bnovo)&&(iteracao<iteracoesmax)
    b=bnovo;
    iteracao=iteracao+1;
    disp(iteracao);
    
    // cálculo da distância euclidiana do vetor de entrada
    // com cada centróide
    for entrada=1:40 
        maisproximo=1000;
        for j=1:k
            distancia=sqrt((cluster(j,1)-pontos(entrada,1))^2 + (cluster(j,2)-pontos(entrada,2))^2);
            //disp(distancia);
            if distancia<maisproximo
                maisproximo=distancia;
                centroide_maisproximo=j;
            end
           bnovo(entrada)=centroide_maisproximo;
          
        end
    end

    // atualização das centróides
    for j=1:k
        soma=[0 0];
        elementos=0;
        for entrada=1:40
            if b(entrada)==j
            soma=soma+pontos(entrada,:)
            elementos=elementos+1;
            end
        end
        if elementos ~=0
           cluster(j,:)=soma/elementos;
        end
    end
end

// mostrando os agrupamentos
for entrada=1:40
    if  bnovo(entrada)==1
        plot(pontos(entrada, 1), pontos(entrada,2), 'k*');
    elseif bnovo(entrada)==2
        plot(pontos(entrada, 1), pontos(entrada,2), 'r*');
    elseif bnovo(entrada)==3
        plot(pontos(entrada, 1), pontos(entrada,2), 'b*');
    else
        bnovo(entrada)==4
        plot(pontos(entrada, 1), pontos(entrada,2), 'm*');
    end
    
end

for j=1:k
    plot(cluster(j, 1), cluster(j,2), 'gs');
end

