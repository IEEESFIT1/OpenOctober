<?php

use Psr\Http\Message\ResponseInterface as Response;
use Psr\Http\Message\ServerRequestInterface as Request;

$app = new \Slim\App;

// Get Single Customer 
$app->get('/api/customers/{id}', function (Request $request, Response $response) {
    
    $id = $request->getAttribute('id');

    $sql = "SELECT * FROM customers WHERE id=$id";

    try {
        // Get DB Object
        $db = new db();
        // Connect DB
        $conn = $db->connect();

        $stmt = $conn->query($sql);

        $customer = $stmt->fetchAll(PDO::FETCH_OBJ);
        $conn = null;
        
        echo json_encode($customer);
    } catch (PDOException $e) {
        echo '{"error": {"text": ' . $e->getMessage() . '}}';
    }
});


// Post Add Customer 
$app->post('/api/customers/add', function (Request $request, Response $response) {
    
    $firstname = $request->getServerParams('first_name');
    $lastname = $request->getServerParams('last_name');
    $phone = $request->getServerParams('phone');
    $email = $request->getServerParams('email');
    $address = $request->getServerParams('address');
    $city = $request->getServerParams('city');
    $state = $request->getServerParams('state');


    $sql = "INSERT INTO customers (first_name,last_name,phone,email,address,city,state)
    VALUES (:fiest_name,:last_name,:phone,:email,:address,:city,:state);";    

    try {
        // Get DB Object
        $db = new db();
        // Connect DB
        $conn = $db->connect();

        $stmt = $conn->prepare($sql);
        $stmt->bindParam(':first_name',$firstname);
        $stmt->bindParam(':last_name',$lastname);
        $stmt->bindParam(':phone',$phone);
        $stmt->bindParam(':email',$email);
        $stmt->bindParam(':address',$address);
        $stmt->bindParam(':city',$city);
        $stmt->bindParam(':state',$state);
        
        $stmt->execute();
        $conn = null;
        
        echo '{"notice": {"text":"Customer Added"}}';
    } catch (PDOException $e) {
        echo '{"error": {"text": ' . $e->getMessage() . '}}';
    }
});


// Put Update Customer 
$app->put('/api/customers/update/{id}', function (Request $request, Response $response) {
    $id = $request->getAttribute('id');
    $firstname = $request->getServerParams('first_name');
    $lastname = $request->getServerParams('last_name');
    $phone = $request->getServerParams('phone');
    $email = $request->getServerParams('email');
    $address = $request->getServerParams('address');
    $city = $request->getServerParams('city');
    $state = $request->getServerParams('state');


    $sql = "UPDATE customers SET
    first_name = :first_name,
    last_name = :last_name,
    phone = :phone,
    email = :email,
    address = :address,
    city = :city,
    staate = :state
    WHERE id = $id";    

    try {
        // Get DB Object
        $db = new db();
        // Connect DB
        $conn = $db->connect();

        $stmt = $conn->prepare($sql);
        $stmt->bindParam(':first_name',$firstname);
        $stmt->bindParam(':last_name',$lastname);
        $stmt->bindParam(':phone',$phone);
        $stmt->bindParam(':email',$email);
        $stmt->bindParam(':address',$address);
        $stmt->bindParam(':city',$city);
        $stmt->bindParam(':state',$state);
        
        $stmt->execute();
        $conn = null;
        
        echo '{"notice": {"text":"Customer Updated"}}';
    } catch (PDOException $e) {
        echo '{"error": {"text": ' . $e->getMessage() . '}}';
    }
});


// Delete Single Customer 
$app->delete('/api/customers/delete/{id}', function (Request $request, Response $response) {
    
    $id = $request->getAttribute('id');

    $sql = "DELETE FROM customers WHERE id=$id";

    try {
        // Get DB Object
        $db = new db();
        // Connect DB
        $conn = $db->connect();

        $stmt = $conn->prepare($sql);
        $stmt->execute();

        $conn = null;
        echo '{"notice": {"text":"Customer Deleted"}}';
    } catch (PDOException $e) {
        echo '{"error": {"text": ' . $e->getMessage() . '}}';
    }
});

