# pg_genotype
an efficient genotype representation type

<h3>Description</h3>
<p>This type provides efficient, 1-byte packed storage of genotypes. It supports insertions and deletions as I and D, compatibility with some bioinformation software packages. Operators for I/O have been carefully selected based on benchmarking on recent x86_64 hardware. Allele order is preserved, so the type is suitable for haplotype storage. Invalid genotypes are rejected.</p>

<h3>Installation</h3>
<pre>
curl -s -S -L https://github.com/rlichtenwalter/pg_genotype/archive/master.zip > pg_genotype.zip
unzip pg_genotype.zip
(cd pg_genotype-master &amp;&amp; make PG_CONFIG=&lt;optional custom pg_config path&gt;)
(cd pg_genotype-master &amp;&amp; make PG_CONFIG=&lt;optional custom pg_config path&gt; install)
(cd ~postgres &amp;&amp; sudo -u postgres psql -c 'CREATE EXTENSION pg_genotype;')
</pre>

<h3>Usage</h3>
<pre>

</pre>
