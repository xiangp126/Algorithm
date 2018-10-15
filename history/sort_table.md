## Sort Table
### CSS - Style
<!-- css style defined here -->
<style type="text/css">
.table {
    width:98%;
    border-collapse:collapse;
    border-top:2px solid #333;
    border-bottom:2px solid #333;
    border-left-style:none;
}

.tr_th {
    border-bottom:2px solid #333;
}

td {
    font-family: "Trebuchet MS", Arial, Verdana;
    font-size: 15px;
    padding: 5px;
    text-align:center;
    border-bottom: 1px solid #CDC1A7;
    padding: 5px;
}
</style>

<!--th was same as td except that it hilight with black-->
<table class='table'>
    <tr class='tr_th'>
        <th>Sort Method</th>
        <th>Average</th>
        <th>Worst</th>
        <th>Space</th>
        <th>Stable</th>
    </tr>
    <tr>
        <td>bubble</th>
        <td>N<sup>2</sup</td>
        <td>N<sup>2</sup></td>
        <td>O(1)</td>
        <td>&radic;</td>
    </tr>
    <tr>
        <td>insert</th>
        <td>N<sup>2</sup</td>
        <td>N<sup>2</sup></td>
        <td>O(1)</td>
        <td>&radic;</td>
    </tr>
    <tr>
        <td>shell</th>
        <td>Nlog<sub>2</sub><sup>N</sup></td>
        <td>N<sup>1.3</sup></td>
        <td>O(1)</td>
        <td>&Chi;</td>
    </tr>
    <tr>
        <td>heap</th>
        <td>Nlog<sub>2</sub><sup>N</sup></td>
        <td>Nlog<sub>2</sub><sup>N</sup></td>
        <td>O(1)</td>
        <td>&Chi;</td>
    </tr>
    <tr>
        <td>merge</th>
        <td>Nlog<sub>2</sub><sup>N</sup></td>
        <td>Nlog<sub>2</sub><sup>N</sup></td>
        <td>O(n)</td>
        <td>&radic;</td>
    </tr>
    <tr>
        <td>quick</th>
        <td>Nlog<sub>2</sub><sup>N</sup></td>
        <td>N<sup>2<sup></td>
        <td>log<sub>2</sub><sup>N</sup></td>
        <td>&Chi;</td>
    </tr>
        <tr>
        <td>count</th>
        <td>O(N + K)</td>
        <td>O(N + K)</td>
        <td>O(N + K)</td>
        <td>&Chi;</td>
    </tr>
    <tr>
        <td>radix</th>
        <td>O(d(n + rd))</td>
        <td>O(d(n + rd))</td>
        <td>O(rd)</td>
        <td>&radic;</td>
    </tr>
</table>