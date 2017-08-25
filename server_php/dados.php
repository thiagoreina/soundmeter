<?php
  $data =$_GET['data'];
  $alerta =$_GET['alerta'];
   
  $conexao = mysql_connect('localhost','root',''); // se conecta ao servidor onde está o banco de dados
  
  mysql_select_db('arduino',$conexao); // seleciona o banco de dados de acordo com a conexão
  
  $sql = "insert into dataSound (data , alerta) values ('$data','$alerta')"; // adiciona os campos no banco de dados
  
  $resultado = mysql_query($sql) or die ("Erro .:" . mysql_error()); // se for armazenado com sucesso irá retornar com "1"
  if($resultado)
          echo "1";
   else                                                              // se ocorrer um erro vai retornar com "0"
          echo "0";
?>