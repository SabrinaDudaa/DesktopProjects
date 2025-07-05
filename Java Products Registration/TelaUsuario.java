import javax.swing.*;
import java.awt.*;

public class TelaUsuario extends JFrame {

    private JButton botaoCadastrar;
    private JButton botaoListaProduto;
    private JButton botaoLimpar;
    private JTextField txtNomeProduto;
    private JTextField intQuantProduto;
    private JTextField doubPrecoProduto;
    private JLabel lblNomeProduto;
    private JLabel lblPrecoProduto;
    private JLabel lblQuantProduto;
    private JLabel lblMensagem;

    // Construtor para configurar a interface
    public TelaUsuario() {
        super("Cadastro de Produtos");
        setLayout(new FlowLayout());

        lblNomeProduto = new JLabel("Nome do produto:");
        txtNomeProduto = new JTextField(30);

        lblPrecoProduto = new JLabel("Preço do produto:");
        doubPrecoProduto = new JTextField(10);

        lblQuantProduto = new JLabel("Quantidade do produto:");
        intQuantProduto = new JTextField(5);

        botaoCadastrar = new JButton("Cadastrar Produto");
        botaoListaProduto = new JButton("Listar Produtos");
        botaoLimpar = new JButton("Limpar Campos");

        lblMensagem = new JLabel("<html><body style='width: 400px;'></body></html>");

        // Adicionando componentes à tela
        add(lblNomeProduto);
        add(txtNomeProduto);
        add(lblPrecoProduto);
        add(doubPrecoProduto);
        add(lblQuantProduto);
        add(intQuantProduto);
        add(botaoCadastrar);
        add(botaoListaProduto);
        add(botaoLimpar);
        add(lblMensagem);

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(500, 300);
        setLocationRelativeTo(null);
        setVisible(true);
    }

    // Getters para acessar os componentes
    public JButton getBotaoCadastrar() { return botaoCadastrar; }
    public JButton getBotaoListaProduto() { return botaoListaProduto; }
    public JButton getBotaoLimpar() { return botaoLimpar; }
    public JTextField getTxtNomeProduto() { return txtNomeProduto; }
    public JTextField getIntQuantProduto() { return intQuantProduto; }
    public JTextField getDoubPrecoProduto() { return doubPrecoProduto; }
    public JLabel getLblMensagem() { return lblMensagem; }
}
