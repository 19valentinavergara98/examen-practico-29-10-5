

document.getElementById('btnReset').onclick = async function (e) {
    e.preventDefault();

    n = document.getElementById('numero').value;
    orden = "resetear";
    
    response = await fetch(`/cgi-bin/funciones.cgi`,{
        method: 'POST',
        headers: {
            'Content-Type': 'application/x-www-form-urlencoded'
        },
        body: new URLSearchParams({
            'numero':n,
            'orden':orden
        })
    });
    data = await response.text();
    document.getElementById('resultado').innerHTML = decodeURI(data);
};


document.getElementById('btnAdd').onclick = async function (e) {
    e.preventDefault();

    orden = "añadir";
    
    response = await fetch(`/cgi-bin/funciones.cgi`,{
        method: 'POST',
        headers: {
            'Content-Type': 'application/x-www-form-urlencoded'
        },
        body: new URLSearchParams({
            'orden':orden
        })
    });
    data = await response.json();
    document.getElementById('numero').value = decodeURI(data.numero);
    document.getElementById('resultado').innerHTML = decodeURI(data.mensaje);
};