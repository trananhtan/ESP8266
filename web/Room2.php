<?php

require "dbcon.php";
$query1 ="SELECT * FROM `R2`";
$data1 =mysqli_query($connect,$query1);
while($row =mysqli_fetch_assoc($data1))
{
    echo $row['Ten']; 
    echo"="; 
    echo $row['Var'] ;
    echo "<br>";
}
?>