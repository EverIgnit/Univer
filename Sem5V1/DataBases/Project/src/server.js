import app from './main.js';

export default function server() {
    try {
        const port = '7777';
        app.listen(port);
        app.set('port', port);
        console.log(`app listen ${port} port`);
        return 0;
    } catch (error) {
        console.log(error);
        return 1;
    }
}