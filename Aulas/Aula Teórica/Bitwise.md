<style>
table, td {
    margin-left: auto;
    margin-right: auto;
    text-align: center;
    border: solid 1px white;
}
.titulo {
    font-weight: bold;
}
</style>

## Operador Complemento (Bitwise NOT)
- Retorna o número que, representado em base binária, é o complemento de 1 do binário recebido como input
- Se utilizamos esse operador em um número qualquer, devemos transformá-lo para sua representação binária e inverter cada bit dessa representação, isto é, transformar os 0's em 1's e vice-versa;
- O número seis em sistema binário é representado por '0110', ao utilizarmos o bitwise not nele, recebemos '1001' como output. '1001' é a representação binária do inteiro -7.
###  Implementação em c++
```cpp
int main() {
    int n = 6;
    int ans;
    ans = ~n;
    cout << ans << endl;
    return 0;
}
```
## Operador Bitwise OR ( | )
- Compara dois números bit a bit, se algum dos bits for '1' na i-ésima posição, então o i-ésimo bit do output será '1', caso contrário, será '0'
- Essa operação está representada na tabela à seguir:
<table>
    <tr>
        <td class="titulo">A</td>   
        <td class="titulo">B</td>    
        <td class="titulo">A or B</td>
    </tr>
    <tr>
        <td>0</td>
        <td>0</td>
        <td>0</td>
    </tr>
    <tr>
        <td>1</td>
        <td>0</td>
        <td>1</td>
    </tr>
    <tr>
        <td>0</td>
        <td>1</td>
        <td>1</td>
    </tr>
    <tr>
        <td>1</td>
        <td>1</td>
        <td>1</td>
    </tr>
</table>

## Operador Bitwise And (&)
- Compara dois números bit a bit, se algum dos bits for '0' na i-ésima posição, então o i-ésimo bit do output será '0', caso contrário, será '1'
- Essa operação está representada na tabela à seguir:
<table>
    <tr>
        <td class="titulo">A</td>   
        <td class="titulo">B</td>    
        <td class="titulo">A or B</td>
    </tr>
    <tr>
        <td>0</td>
        <td>0</td>
        <td>0</td>
    </tr>
    <tr>
        <td>1</td>
        <td>0</td>
        <td>0</td>
    </tr>
    <tr>
        <td>0</td>
        <td>1</td>
        <td>0</td>
    </tr>
    <tr>
        <td>1</td>
        <td>1</td>
        <td>1</td>
    </tr>
</table>