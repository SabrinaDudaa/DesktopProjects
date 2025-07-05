import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.List;

public class BotoesCadastro {

    private TelaUsuario telaUsuario;

    // Construtor para receber a interface gráfica
    public BotoesCadastro(TelaUsuario telaUsuario) {
        this.telaUsuario = telaUsuario;
        configurarEventos();
    }

    // Configuração dos eventos dos botões
    private void configurarEventos() {
        // Evento para o botão de cadastrar produto
        telaUsuario.getBotaoCadastrar().addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent ev) {
                String nome = telaUsuario.getTxtNomeProduto().getText().trim();
                String precoText = telaUsuario.getDoubPrecoProduto().getText().trim();
                String quantidadeText = telaUsuario.getIntQuantProduto().getText().trim();

                if (nome.isEmpty()) {
                    telaUsuario.getLblMensagem().setText("Erro: O nome do produto não pode ser vazio!");
                    return;
                }

                try {
                    double preco = Double.parseDouble(precoText);
                    int quantidade = Integer.parseInt(quantidadeText);

                    if (preco <= 0 || quantidade <= 0) {
                        telaUsuario.getLblMensagem().setText("Erro: Preço e quantidade devem ser positivos!");
                        return;
                    }

                    InfoCadastro novoProduto = new InfoCadastro(nome, preco, quantidade);
                    InfoCadastro.adicionarProduto(novoProduto);
                    telaUsuario.getLblMensagem().setText("Produto cadastrado com sucesso!");
                } catch (NumberFormatException e) {
                    telaUsuario.getLblMensagem().setText("Erro: Preço e quantidade devem ser numéricos!");
                }
            }
        });

        // Evento para listar produtos
        telaUsuario.getBotaoListaProduto().addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent ev) {
                List<InfoCadastro> produtos = InfoCadastro.getListaProdutos();

                if (produtos.isEmpty()) {
                    telaUsuario.getLblMensagem().setText("Nenhum produto cadastrado.");
                } else {
                    StringBuilder detalhes = new StringBuilder("<html><body style='width: 400px;'>");
                    for (InfoCadastro produto : produtos) {
                        detalhes.append("Nome: ").append(produto.getNomeProduto())
                                .append("<br>Preço: ").append(produto.getPreco())
                                .append("<br>Estoque: ").append(produto.getQuantEstoque())
                                .append("<br><br>");
                    }
                    detalhes.append("</body></html>");
                    telaUsuario.getLblMensagem().setText(detalhes.toString());
                }
            }
        });

        // Evento para limpar campos
        telaUsuario.getBotaoLimpar().addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent ev) {
                telaUsuario.getTxtNomeProduto().setText("");
                telaUsuario.getIntQuantProduto().setText("");
                telaUsuario.getDoubPrecoProduto().setText("");
                telaUsuario.getLblMensagem().setText("");
            }
        });
    }
}
