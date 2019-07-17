# TG2
Tema:<br />
Ataque de Negação de Serviço por Reflexão Amplificada: Explorando o protocolo Domain Name System para a Detecção e Identificação de Refletores. <br />
<br />
Este trabalho propõe uma ferramenta que realize a detecção e a identificação de refletores, principais agentes em ataques de Negação de serviço por reflexão amplificada. Para a realização da detecção, os métodos utilizados até o momento consideram apenas a análise de pacotes referentes ao protocolo Domain Name System (DNS). <br />
<br />
Esta ferramenta é capaz de detectar e identificar refletores em ataques de negação de serviço por reflexão amplificada. Após a detecção, o IP do refletor é enviado para um PROXY responsável por bloquear o tráfego. Para testar, é necessário executar o detector e o Proxy.<br />
<br />
Arquivo de configuração:<br />
API.conf<br />
<br />
No arquivo de configuração é possível alterar:
1. o limite de tolerância dos valores dos contadores; <br />
2. IP:porta do Proxy;<br />
3. modo debug: opção de log detalhado sobre o tráfego.<br />
<br />
Execução Detector: <br />
bash ./API/scripts/run.sh<br />
<br />
Execução Proxy (porta 7000):<br />
bash ./Proxy/scripts/run.sh<br />
<br />
Orientação: João José Costa Gondim  <br />
Universidade de Brasília - 2018/1 ~ 2019/1 <br />
