import java.util.ArrayList;
import java.util.List;

public class InfoCadastro {

    // Atributos privados
    private String nomeProduto;
    private double preco;
    private int quantEstoque;

    // Lista para armazenar produtos cadastrados
    private static List<InfoCadastro> listaProdutos = new ArrayList<>();

    // Construtor
    public InfoCadastro(String nomeProduto, double preco, int quantEstoque) {
        this.nomeProduto = nomeProduto;
        this.preco = preco;
        this.quantEstoque = quantEstoque;
    }

    // Getters e Setters
    public String getNomeProduto() {
        return nomeProduto;
    }

    public void setNomeProduto(String nomeProduto) {
        this.nomeProduto = nomeProduto;
    }

    public double getPreco() {
        return preco;
    }

    public void setPreco(double preco) {
        this.preco = preco;
    }

    public int getQuantEstoque() {
        return quantEstoque;
    }

    public void setQuantEstoque(int quantEstoque) {
        this.quantEstoque = quantEstoque;
    }

    // Métodos para gerenciar a lista de produtos
    public static void adicionarProduto(InfoCadastro produto) {
        listaProdutos.add(produto);
    }

    public static List<InfoCadastro> getListaProdutos() {
        return listaProdutos;
    }
}
