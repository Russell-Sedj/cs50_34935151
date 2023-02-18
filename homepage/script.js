document.addEventListener('DOMContentLoaded', function(){
    let nameNode = document.getElementById("name");
    nameNode.addEventListener('click', function(){
        nameNode.style.backgroundColor = 'blue';
        alert('Welcome');
    })
})