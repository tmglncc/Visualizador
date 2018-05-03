# 3d Visualizer of Tumor Growth (GLUT)

- [Demonstrações](https://www.youtube.com/playlist?list=PLBiKOq-ULPIZfYM7N7ghntbDf0wbeoBYo)

## Dependências

### Ubuntu:

- GLEW: sudo apt-get install libglew-dev glew-utils libglew-dbg
- GLUT: sudo apt-get install freeglut3 freeglut3-dev
- GLM: sudo apt-get install libglm-dev libglm-doc
- libconfig: sudo apt install libconfig++-dev libconfig++-doc libconfig++-dbg
- OpenCV: sudo apt-get install build-essential cmake git libgtk2.0-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev qt5-default qttools5-dev-tools libopencv-dev

## Compilando o projeto

1. `make clean`
2. `make`

## Executando o visualizador

`make run`

## Arquivo `config.cfg`
Possui as configurações do projeto. É possível mudar as configurações sem recompilar o projeto.

## Atalhos

### Screenshot

- `p`/`P` - Screenshot PNG/JPG
- `o`/`O` - Inicia/Para sequência de screenshots

### Controle das linhas de corte

- `a`/`A` - Move a linha de corte da esquerda para fora/centro
- `s`/`S` - Move a linha de corte inferior para fora/centro
- `d`/`D` - Move a linha de corte da direita para fora/centro
- `w`/`W` - Move a linha de corte superior para fora/centro
- `q`/`Q` - Move a linha de corte frontal para fora/centro
- `e`/`E` - Move a linha de corte traseira para fora/centro
- `0` - Reseta as linhas

### Visibilidade dos elementos

- `l` e `L` - Mostra/Oculta as linhas de corte
- `i` e `I` - Mostra/Oculta as informações

#### Visibilidade das células

- `1` - Mostra/Oculta células NEC
- `2` - Mostra/Oculta células QUI
- `3` - Mostra/Oculta células PRO
- `4` - Mostra/Oculta células HIP
- `5` - Mostra/Oculta células APO
- `6` - Mostra/Oculta células G1
- `7` - Mostra/Oculta células NOR

### Controle de estados

- `,` - Estado anterior / PAUSE
- `.` - Próximo estado / PAUSE
- `>` - Play
- `<` - Reverso
- `n`/`N` - Primeiro/Último estado

### Modos de visualização

- `f` ou `F` - Tela cheia
- `z` - Modo STD
- `x` - Modo NUT
- `c` - Modo EGF
